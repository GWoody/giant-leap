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
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation *GestureImplementation::Create( const Leap::Gesture &gesture )
{
	switch( gesture.type() )
	{
		case Gesture::Type::TYPE_SWIPE:
		{
			Leap::SwipeGesture ls( gesture );
			return new SwipeGestureImplementation( ls );
		}

		case Gesture::Type::TYPE_CIRCLE:
		{
			Leap::CircleGesture lc( gesture );
			return new CircleGestureImplementation( lc );
		}

		case Gesture::Type::TYPE_SCREEN_TAP:
		{
			Leap::ScreenTapGesture ls( gesture );
			return new TapGestureImplementation( ls );
		}

		case Gesture::Type::TYPE_KEY_TAP:
		{
			Leap::KeyTapGesture lk( gesture );
			return new TapGestureImplementation( lk );
		}
	}

	C_breakpoint();
	return NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation *GestureImplementation::Create( Gesture::Type type )
{
	switch( type )
	{
		case Gesture::Type::TYPE_SWIPE:
		{
			return new SwipeGestureImplementation();
		}

		case Gesture::Type::TYPE_CIRCLE:
		{
			return new CircleGestureImplementation();
		}

		case Gesture::Type::TYPE_SCREEN_TAP:
		{
			return new TapGestureImplementation();
		}

		case Gesture::Type::TYPE_KEY_TAP:
		{
			return new TapGestureImplementation();
		}
	}

	C_breakpoint();
	return NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation::GestureImplementation()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation::GestureImplementation( const Leap::Gesture &gesture )
{
	FromLeap( gesture );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureImplementation::GestureImplementation( BufferRead *buffer )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void GestureImplementation::FromLeap( const Leap::Gesture &gesture )
{
	_id = gesture.id();
	_type = (Gesture::Type)gesture.type();
	_duration = gesture.duration();
	_durationSeconds = gesture.durationSeconds();
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

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void GestureImplementation::Translate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void GestureImplementation::Rotate( const Vector &v )
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
	return HandList();
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