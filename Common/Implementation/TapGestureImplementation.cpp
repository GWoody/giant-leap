/*
===============================================================================

	Giant Leap

	File	:	TapGestureImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `TapGesture` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "TapGestureImplementation.h"
#include "SharedObject.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TapGestureImplementation::TapGestureImplementation( FrameImplementation &frame ) :
	GestureImplementation( frame )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TapGestureImplementation::TapGestureImplementation( FrameImplementation &frame, const Leap::KeyTapGesture &tap ) :
	GestureImplementation( frame )
{
	FromLeap( tap );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TapGestureImplementation::TapGestureImplementation( FrameImplementation &frame, const Leap::ScreenTapGesture &tap ) :
	GestureImplementation( frame )
{
	FromLeap( tap );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TapGestureImplementation::FromLeap( const Leap::KeyTapGesture &tap )
{
	_position = tap.position();
	_direction = tap.direction();
	_progress = tap.progress();

	GestureImplementation::FromLeap( tap );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TapGestureImplementation::FromLeap( const Leap::ScreenTapGesture &tap )
{
	_position = tap.position();
	_direction = tap.direction();
	_progress = tap.progress();

	GestureImplementation::FromLeap( tap );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool TapGestureImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'tap!' );

	buffer->WriteVector( _position );
	buffer->WriteVector( _direction );
	buffer->WriteFloat( _progress );

	return GestureImplementation::Serialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool TapGestureImplementation::Unserialize( BufferRead *buffer )
{
	if( buffer->ReadInt() != 'tap!' )
	{
		std::cout << "Expected 'tap!', got junk." << std::endl;
		return false;
	}

	_position = buffer->ReadVector();
	_direction = buffer->ReadVector();
	_progress = buffer->ReadFloat();

	return GestureImplementation::Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TapGestureImplementation::Translate( const Vector &v )
{
	_position += v;

	GestureImplementation::Translate( v );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TapGestureImplementation::Rotate( const Matrix &pry )
{
	_position = pry.transformDirection( _position );
	_direction = pry.transformDirection( _direction );

	GestureImplementation::Rotate( pry );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector TapGestureImplementation::position() const
{
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector TapGestureImplementation::direction() const
{
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float TapGestureImplementation::progress() const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable TapGestureImplementation::pointable() const
{
	C_breakpoint();
	return Pointable();
}