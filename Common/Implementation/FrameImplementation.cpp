/*
===============================================================================

	Giant Leap

	File	:	FrameImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the actual logic behind the `Frame` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "FrameImplementation.h"
#include "HandImplementation.h"
#include "GestureImplementation.h"
#include "ListBaseImplementation.h"
#include "SharedObject.h"
#include "ControllerImplementation.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation::FrameImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation::FrameImplementation( const Leap::Frame &frame )
{
	FromLeap( frame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation::FrameImplementation( BufferRead *buffer )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::FromLeap( const Leap::Frame &frame )
{
	const Leap::HandList &hands = frame.hands();
	const Leap::GestureList &gestures = frame.gestures();

	//
	// Store frame info.
	//
	_id = frame.id();
	_timestamp = frame.timestamp();

	//
	// Store hands.
	//
	for( int i = 0; i < hands.count(); i++ )
	{
		HandImplementation *hi = new HandImplementation( hands[i] );
		Hand h( hi );

		_hands.push_back( HandPair_t( h, hi ) );
	}

	//
	// Store gestures.
	//
	for( int i = 0; i < gestures.count(); i++ )
	{
		GestureImplementation *gi = GestureImplementation::Create( *this, gestures[i] );
		Gesture g( gi );

		_gestures.push_back( GesturePair_t( g, gi ) );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BufferWrite FrameImplementation::Serialize()
{
	BufferWrite buf;

	buf.WriteInt( 'frmh' );

	//
	// Write frame info.
	//
	buf.WriteVector( _deviceTranslation );
	buf.WriteLongLong( _id );
	buf.WriteLongLong( _timestamp );

	//
	// Write hands.
	//
	buf.WriteShort( _hands.size() );
	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		_hands[i].GetImplementation()->Serialize( &buf );
	}

	//
	// Write gestures.
	//
	buf.WriteShort( _gestures.size() );
	for( unsigned int i = 0; i < _gestures.size(); i++ )
	{
		int type = _gestures[i].GetImplementation()->type();

		if( type != Gesture::TYPE_INVALID )
		{
			buf.WriteShort( type );
			_gestures[i].GetImplementation()->Serialize( &buf );
		}
	}

	buf.WriteInt( 'frmt' );

	return buf;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Unserialize( BufferRead *buffer )
{
	_hands.clear();
	_gestures.clear();

	if( buffer->ReadInt() != 'frmh' )
	{
		std::cerr << "FrameImplementation::Unserialize - failed to frame head" << std::endl;
		return;
	}

	//
	// Read frame info.
	//
	_deviceTranslation = buffer->ReadVector();
	_id = buffer->ReadLongLong();
	_timestamp = buffer->ReadLongLong();

	//
	// Read hands.
	//
	short handCount = buffer->ReadShort();
	while( handCount )
	{
		HandImplementation *hi = new HandImplementation();
		if( !hi->Unserialize( buffer ) )
		{
			std::cerr << "FrameImplementation::Unserialize - failed to read hand" << std::endl;
			delete hi;
			return;
		}

		Hand h( hi );
		_hands.push_back( HandPair_t( h, hi ) );

		--handCount;
	}

	//
	// Read gestures.
	//
	short gestureCount = buffer->ReadShort();
	while( gestureCount )
	{
		Gesture::Type type = (Gesture::Type)buffer->ReadShort();
		GestureImplementation *gi = GestureImplementation::Create( *this, type );
		if( !gi->Unserialize( buffer ) )
		{
			std::cerr << "FrameImplementation::Unserialize - failed to read gesture" << std::endl;
			delete gi;
			return;
		}

		Gesture g( gi );
		_gestures.push_back( GesturePair_t( g, gi ) );
		--gestureCount;
	}

	if( buffer->ReadInt() != 'frmt' )
	{
		std::cerr << "FrameImplementation::Unserialize - failed to frame tail" << std::endl;
		return;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Translate( const Vector &v )
{
	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		_hands[i].GetImplementation()->Translate( v );
	}

	for( unsigned int i = 0; i < _gestures.size(); i++ )
	{
		_gestures[i].GetImplementation()->Translate( v );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Rotate( const Vector &v )
{
	Matrix pitch( Vector::right(), v.x );
	Matrix roll( Vector::backward(), v.y );
	Matrix yaw( Vector::up(), v.z );
	Matrix pry = pitch * roll * yaw;

	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		_hands[i].GetImplementation()->Rotate( pry );
	}

	for( unsigned int i = 0; i < _gestures.size(); i++ )
	{
		_gestures[i].GetImplementation()->Rotate( pry );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation	FrameImplementation::operator+( const FrameImplementation &rhs ) const
{
	FrameImplementation f;

	f._id = min( _id, rhs._id );
	f._timestamp = min( _timestamp, rhs._timestamp );

	// Use the frame with the largest number of hands as the "master" frame.
	// Try to match frames from the "slave" hand to the master.
	const std::vector<HandPair_t> &master = ( _hands.size() < rhs._hands.size() ) ? rhs._hands : _hands;
	const FrameImplementation &slave = ( _hands.size() < rhs._hands.size() ) ? *this : rhs;
	for( unsigned int i = 0; i < master.size(); i++ )
	{
		HandImplementation *mh = master[i].GetImplementation();
		HandImplementation *sh = FindMatchingHand( mh, slave );

		if( !sh )
		{
			f._hands.push_back( master[i] );
		}
		else
		{
			HandImplementation *newHand = new HandImplementation();
			(*newHand) = (*mh) + (*sh);

			Hand newh( newHand );
			f._hands.push_back( HandPair_t( newh, newHand ) );
		}
	}

	// TODO: merge gestures

	return f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation	FrameImplementation::operator*( float scale ) const
{
	FrameImplementation f;

	f._id = _id;
	f._timestamp = _timestamp;

	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		const HandImplementation currentHand = *_hands[i].GetImplementation();

		HandImplementation *newHand = new HandImplementation( currentHand );
		Hand h( newHand );

		(*newHand) = (*newHand) * scale;

		f._hands.push_back( HandPair_t( h, newHand ) );
	}

	// TODO: scale gestures

	return f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation	FrameImplementation::operator/( float scale ) const
{
	FrameImplementation f;

	f._id = _id;
	f._timestamp = _timestamp;

	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		const HandImplementation currentHand = *_hands[i].GetImplementation();

		HandImplementation *newHand = new HandImplementation( currentHand );
		Hand h( newHand );

		(*newHand) = (*newHand) / scale;

		f._hands.push_back( HandPair_t( h, newHand ) );
	}

	// TODO: scale gestures

	return f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int64_t FrameImplementation::id() const
{
	return _id;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int64_t FrameImplementation::timestamp() const
{
	return _timestamp;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
InteractionBox FrameImplementation::interactionBox() const
{
	C_breakpoint();
	return InteractionBox();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::currentFramesPerSecond() const
{
	return 60.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char *FrameImplementation::toCString() const
{
	C_breakpoint();
	return "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandList FrameImplementation::hands() const
{
	ListBaseImplementation<Hand> *list = new ListBaseImplementation<Hand>;

	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		list->push_back( _hands[i].GetInterface() );
	}

	return HandList( *list );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableList FrameImplementation::pointables() const
{
	C_breakpoint();
	return PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerList FrameImplementation::fingers() const
{
	C_breakpoint();
	return FingerList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ToolList FrameImplementation::tools() const
{
	C_breakpoint();
	return ToolList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureList FrameImplementation::gestures() const
{
	ListBaseImplementation<Gesture> *list = new ListBaseImplementation<Gesture>; 

	for( unsigned int i = 0; i < _gestures.size(); i++ )
	{
		list->push_back( _gestures[i].GetInterface() );
	}

	return GestureList( *list );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Hand FrameImplementation::hand( int32_t id ) const
{
	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		if( _hands[i].GetImplementation()->id() == id )
		{
			return _hands[i].GetInterface();
		}
	}

	return Hand::invalid();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable FrameImplementation::pointable( int32_t id )
{
	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		Pointable p = _hands[i].GetImplementation()->pointable( id );
		if( p != Pointable::invalid() )
		{
			return p;
		}
	}

	return Pointable::invalid();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Finger FrameImplementation::finger( int32_t id ) const
{
	C_breakpoint();
	return Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Tool FrameImplementation::tool( int32_t id ) const
{
	C_breakpoint();
	return Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Gesture FrameImplementation::gesture( int32_t id ) const
{
	return Gesture();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureList FrameImplementation::gestures( const Frame &sinceFrame ) const
{
	return GestureList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector FrameImplementation::translation( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::translationProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector FrameImplementation::rotationAxis( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationAngle( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationAngle( const Frame &sinceFrame, const Vector& axis ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix FrameImplementation::rotationMatrix( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Matrix();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::scaleFactor( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::scaleProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
// Find a hand that closely matches the position of the given hand.
//-----------------------------------------------------------------------------
HandImplementation *FrameImplementation::FindMatchingHand( HandImplementation *hand, const FrameImplementation &frame ) const
{
	const Vector &palmPosition = hand->palmPosition();

	for( unsigned int i = 0; i < frame._hands.size(); i++ )
	{
		HandImplementation *test = frame._hands[i].GetImplementation();
		const Vector &testPosition = test->palmPosition();

		// Just ensure they're within 5cm of each other.
		if( palmPosition.distanceTo( testPosition ) < 50 )
		{
			return test;
		}
	}

	return NULL;
}