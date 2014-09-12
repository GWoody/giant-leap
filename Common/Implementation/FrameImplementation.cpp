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

#include "Leap.h"
#include "FrameImplementation.h"
#include "HandImplementation.h"
#include "GestureImplementation.h"
#include "ListBaseImplementation.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation::FrameImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation::FrameImplementation( const Frame &frame )
{
	FromLeap( frame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::FromLeap( const Frame &frame )
{
	const HandList &hands = frame.hands();
	const GestureList &gestures = frame.gestures();

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
		HandImplementation hi( hands[i] );
		_hands.push_back( hi );
	}

	//
	// Store gestures.
	//
	for( int i = 0; i < gestures.count(); i++ )
	{
		GestureImplementation gi( gestures[i] );
		_gestures.push_back( gi );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BufferWrite FrameImplementation::Serialize()
{
	BufferWrite buf;

	//
	// Write frame info.
	//
	buf.WriteLongLong( _id );
	buf.WriteLongLong( _timestamp );

	//
	// Write hands.
	//
	buf.WriteInt( 'hand' );
	buf.WriteShort( _hands.size() );
	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		_hands[i].Serialize( &buf );
	}

	//
	// Write gestures.
	//
	buf.WriteInt( 'gstr' );
	buf.WriteShort( _gestures.size() );
	for( unsigned int i = 0; i < _gestures.size(); i++ )
	{
		_gestures[i].Serialize( &buf );
	}

	return buf;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Unserialize( BufferRead *buffer )
{
	int tag;

	_hands.clear();
	_gestures.clear();

	//
	// Read frame info.
	//
	_id = buffer->ReadLongLong();
	_timestamp = buffer->ReadLongLong();

	//
	// Read hands.
	//
	tag = buffer->ReadInt();
	if( tag != 'hand' )
	{
		fprintf( stderr, "FrameImplementation::Unserialize - hand tag invalid!\n" );
		return;
	}

	short handCount = buffer->ReadShort();
	while( handCount )
	{
		HandImplementation hi( buffer );
		_hands.push_back( hi );
		--handCount;
	}

	//
	// Read gestures.
	//
	tag = buffer->ReadInt();
	if( tag != 'gstr' )
	{
		fprintf( stderr, "FrameImplementation::Unserialize - hand tag invalid!\n" );
		return;
	}

	short gestureCount = buffer->ReadShort();
	while( gestureCount )
	{
		GestureImplementation gi( buffer );
		_gestures.push_back( gi );
		--gestureCount;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Translate( const Vector &v )
{
	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		_hands[i].Translate( v );
	}

	for( unsigned int i = 0; i < _gestures.size(); i++ )
	{
		_gestures[i].Translate( v );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Rotate( const Vector &v )
{
	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		_hands[i].Rotate( v );
	}

	for( unsigned int i = 0; i < _gestures.size(); i++ )
	{
		_gestures[i].Rotate( v );
	}
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
	breakpoint();
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
	breakpoint();
	return "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandList FrameImplementation::hands() const
{
	ListBaseImplementation<Hand> list;

	for( unsigned int i = 0; i < _hands.size(); i++ )
	{
		HandImplementation *hi = (HandImplementation *)&_hands[i];
		Hand h( hi );
		list.push_back( h );
	}

	return HandList( list );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableList FrameImplementation::pointables() const
{
	breakpoint();
	return PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerList FrameImplementation::fingers() const
{
	breakpoint();
	return FingerList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ToolList FrameImplementation::tools() const
{
	breakpoint();
	return ToolList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureList FrameImplementation::gestures() const
{
	ListBaseImplementation<Gesture> list;

	for( unsigned int i = 0; i < _gestures.size(); i++ )
	{
		GestureImplementation *gi = (GestureImplementation *)&_gestures[i];
		Gesture g( gi );
		list.push_back( g );
	}

	return GestureList( list );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Hand FrameImplementation::hand( int32_t id ) const
{
	return Hand();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable FrameImplementation::pointable( int32_t id )
{
	breakpoint();
	return Pointable();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Finger FrameImplementation::finger( int32_t id ) const
{
	breakpoint();
	return Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Tool FrameImplementation::tool( int32_t id ) const
{
	breakpoint();
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
	breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::translationProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector FrameImplementation::rotationAxis( const Frame &sinceFrame ) const
{
	breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationAngle( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationAngle( const Frame &sinceFrame, const Vector& axis ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix FrameImplementation::rotationMatrix( const Frame &sinceFrame ) const
{
	breakpoint();
	return Matrix();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::scaleFactor( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::scaleProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}