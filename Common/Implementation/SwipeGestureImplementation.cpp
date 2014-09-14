/*
===============================================================================

	Giant Leap

	File	:	SwipeGestureImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `SwipeGesture` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "SwipeGestureImplementation.h"
#include "SharedObject.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SwipeGestureImplementation::SwipeGestureImplementation()
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SwipeGestureImplementation::SwipeGestureImplementation( const Leap::SwipeGesture &swipe ) :
	GestureImplementation( swipe )
{
	FromLeap( swipe );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SwipeGestureImplementation::FromLeap( const Leap::SwipeGesture &swipe )
{
	_startPosition = swipe.startPosition();
	_position = swipe.position();
	_direction = swipe.direction();
	_speed = swipe.speed();

	GestureImplementation::FromLeap( swipe );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool SwipeGestureImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'swpe' );

	buffer->WriteVector( _startPosition );
	buffer->WriteVector( _position );
	buffer->WriteVector( _direction );
	buffer->WriteFloat( _speed );

	return GestureImplementation::Serialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool SwipeGestureImplementation::Unserialize( BufferRead *buffer )
{
	if( buffer->ReadInt() != 'swpe' )
	{
		std::cout << "Expected 'swpe', got junk." << std::endl;
		return false;
	}

	_startPosition = buffer->ReadVector();
	_position = buffer->ReadVector();
	_direction = buffer->ReadVector();
	_speed = buffer->ReadFloat();

	return GestureImplementation::Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SwipeGestureImplementation::Translate( const Vector &v )
{
	GestureImplementation::Translate( v );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SwipeGestureImplementation::Rotate( const Vector &v )
{
	GestureImplementation::Rotate( v );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector SwipeGestureImplementation::startPosition() const
{
	return _startPosition;	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector SwipeGestureImplementation::position() const
{
	return _position;	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector SwipeGestureImplementation::direction() const
{
	return _direction;	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float SwipeGestureImplementation::speed() const
{
	return _speed;	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable SwipeGestureImplementation::pointable() const
{
	C_breakpoint();
	return Pointable();	
}