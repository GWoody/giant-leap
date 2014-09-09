/*
===============================================================================

	Giant Leap

	File	:	Gesture.cpp
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the Giant Leap version of the `Frame` Leap SDK class.

===============================================================================
*/

#include "Leap.h"
#include "GestureImplementation.h"
#include "SharedObject.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Gesture::Gesture( GestureImplementation *ref ) : Interface( ref, this )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Gesture::Gesture() : Interface( (SharedObject *)NULL )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Gesture::Gesture( const Gesture& rhs ) : Interface( rhs.m_object )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Gesture::Type Gesture::type() const
{
	return get<GestureImplementation>()->type();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Gesture::State Gesture::state() const
{
	return get<GestureImplementation>()->state();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int32_t Gesture::id() const
{
	return get<GestureImplementation>()->id();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int64_t Gesture::duration() const
{
	return get<GestureImplementation>()->duration();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Gesture::durationSeconds() const
{
	return get<GestureImplementation>()->durationSeconds();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Frame Gesture::frame() const
{
	return get<GestureImplementation>()->frame();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT HandList Gesture::hands() const
{
	return get<GestureImplementation>()->hands();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT PointableList Gesture::pointables() const
{
	return get<GestureImplementation>()->pointables();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Gesture::isValid() const
{
	return get<GestureImplementation>() != NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Gesture::operator==( const Gesture& rhs ) const
{
	return get<GestureImplementation>() == rhs.get<GestureImplementation>();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Gesture::operator!=( const Gesture& rhs ) const
{
	return get<GestureImplementation>() != rhs.get<GestureImplementation>();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const Gesture &Gesture::invalid()
{
	static Gesture g( NULL );
	return g;
}