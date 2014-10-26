/*
===============================================================================

	Giant Leap

	File	:	GestureImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the actual logic behind the `Gesture` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "GestureImplementation.h"
#include "CircleGestureImplementation.h"
#include "SwipeGestureImplementation.h"
#include "TapGestureImplementation.h"
#include "FrameImplementation.h"
#include "ListBaseImplementation.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation *GestureImplementation::Create( FrameImplementation &frame,const Leap::Gesture &gesture )
{
	switch( gesture.type() )
	{
		case Gesture::Type::TYPE_SWIPE:
		{
			Leap::SwipeGesture ls( gesture );
			return new SwipeGestureImplementation( frame, ls );
		}

		case Gesture::Type::TYPE_CIRCLE:
		{
			Leap::CircleGesture lc( gesture );
			return new CircleGestureImplementation( frame, lc );
		}

		case Gesture::Type::TYPE_SCREEN_TAP:
		{
			Leap::ScreenTapGesture ls( gesture );
			return new TapGestureImplementation( frame, ls );
		}

		case Gesture::Type::TYPE_KEY_TAP:
		{
			Leap::KeyTapGesture lk( gesture );
			return new TapGestureImplementation( frame, lk );
		}
	}

	C_breakpoint();
	return NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation *GestureImplementation::Create( FrameImplementation &frame, Gesture::Type type )
{
	switch( type )
	{
		case Gesture::Type::TYPE_SWIPE:
		{
			return new SwipeGestureImplementation( frame );
		}

		case Gesture::Type::TYPE_CIRCLE:
		{
			return new CircleGestureImplementation( frame );
		}

		case Gesture::Type::TYPE_SCREEN_TAP:
		{
			return new TapGestureImplementation( frame );
		}

		case Gesture::Type::TYPE_KEY_TAP:
		{
			return new TapGestureImplementation( frame );
		}
	}

	C_breakpoint();
	return NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation::GestureImplementation( FrameImplementation &frame ) :
	_frame( frame )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation::GestureImplementation( FrameImplementation &frame, const Leap::Gesture &gesture ) :
	_frame( frame )
{
	FromLeap( gesture );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void GestureImplementation::FromLeap( const Leap::Gesture &gesture )
{
	_id = gesture.id();
	_type = (Gesture::Type)gesture.type();
	_duration = gesture.duration();
	_durationSeconds = gesture.durationSeconds();

	Leap::HandList hands = gesture.hands();
	for( int i = 0; i < hands.count(); i++ )
	{
		_handIds.push_back( hands[i].id() );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool GestureImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'gstr' );

	buffer->WriteInt( _id );
	buffer->WriteInt( _type );
	buffer->WriteLongLong( _duration );
	buffer->WriteFloat( _durationSeconds );

	buffer->WriteInt( _handIds.size() );
	for( unsigned int i = 0; i < _handIds.size(); i++ )
	{
		buffer->WriteInt( _handIds[i] );
	}
	
	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool GestureImplementation::Unserialize( BufferRead *buffer )
{
	if( buffer->ReadInt() != 'gstr' )
	{
		std::cout << "Expected 'gstr', got junk." << std::endl;
		return false;
	}

	_id = buffer->ReadInt();
	_type = (Gesture::Type)buffer->ReadInt();
	_duration = buffer->ReadLongLong();
	_durationSeconds = buffer->ReadFloat();

	int handCount = buffer->ReadInt();
	for( int i = 0; i < handCount; i++ )
	{
		int32_t id = buffer->ReadInt();
		_handIds.push_back( id );
	}

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void GestureImplementation::Translate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void GestureImplementation::Rotate( const Matrix &pry )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int32_t GestureImplementation::id() const
{
	return _id;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Gesture::Type GestureImplementation::type() const
{
	return _type;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Gesture::State GestureImplementation::state() const
{
	C_breakpoint();
	return Gesture::State::STATE_INVALID;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int64_t GestureImplementation::duration() const
{
	return _duration;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float GestureImplementation::durationSeconds() const
{
	return _durationSeconds;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Frame GestureImplementation::frame() const
{
	C_breakpoint();
	return Frame::invalid();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandList GestureImplementation::hands() const
{
	C_breakpoint();

	ListBaseImplementation<Hand> *list = new ListBaseImplementation<Hand>;

	for( unsigned int i = 0; i < _handIds.size(); i++ )
	{
		Hand h = _frame.hand( _handIds[i] );
		list->push_back( h );
	}

	return HandList( *list );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableList GestureImplementation::pointables() const
{
	C_breakpoint();
	return PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char *GestureImplementation::toCString() const
{
	C_breakpoint();
	return "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const std::vector<int32_t> &GestureImplementation::handIds() const
{
	return _handIds;
}