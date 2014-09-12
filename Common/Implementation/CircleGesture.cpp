/*
===============================================================================

	Giant Leap

	File	:	CircleGesture.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `CircleGesture` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "CircleGestureImplementation.h"
#include "SharedObject.h"
using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT CircleGesture::CircleGesture()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT CircleGesture::CircleGesture( const Gesture &rhs ) : Gesture( rhs )
{
	if( rhs.type() != Gesture::TYPE_CIRCLE )
	{
		// Wrong gesture type. Make this gesture instance invalid.
		m_object->DecrementRefCount();
		m_object = NULL;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector CircleGesture::center() const
{
	return isValid() ? get<CircleGestureImplementation>()->center() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector CircleGesture::normal() const
{
	return isValid() ? get<CircleGestureImplementation>()->normal() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float CircleGesture::progress() const
{
	return isValid() ? get<CircleGestureImplementation>()->progress() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float CircleGesture::radius() const
{
	return isValid() ? get<CircleGestureImplementation>()->radius() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable CircleGesture::pointable() const
{
	return isValid() ? get<CircleGestureImplementation>()->pointable() : Pointable();
}