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
using namespace GiantLeap;

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
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool GestureImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'gstr' );

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
	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Gesture::Type GestureImplementation::type() const
{
	return Gesture::Type::TYPE_INVALID;
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
	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float GestureImplementation::durationSeconds() const
{
	return 0.0f;
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