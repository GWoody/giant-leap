/*
===============================================================================

	Giant Leap

	File	:	Gesture.cpp
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the Giant Leap version of the `Frame` Leap SDK class.

===============================================================================
*/

#include "GiantLeap.h"
#include "GestureImplementation.h"
#include "SharedObject.h"
using namespace GiantLeap;

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
	return isValid() ? get<GestureImplementation>()->type() : Gesture::TYPE_INVALID;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Gesture::State Gesture::state() const
{
	return isValid() ? get<GestureImplementation>()->state() : Gesture::STATE_INVALID;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int32_t Gesture::id() const
{
	return isValid() ? get<GestureImplementation>()->id() : -1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int64_t Gesture::duration() const
{
	return isValid() ? get<GestureImplementation>()->duration() : 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Gesture::durationSeconds() const
{
	return isValid() ? get<GestureImplementation>()->durationSeconds() : 0;	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Frame Gesture::frame() const
{
	return isValid() ? get<GestureImplementation>()->frame() : Frame::invalid();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT HandList Gesture::hands() const
{
	return isValid() ? get<GestureImplementation>()->hands() : HandList();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT PointableList Gesture::pointables() const
{
	return isValid() ? get<GestureImplementation>()->pointables() : PointableList();	
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