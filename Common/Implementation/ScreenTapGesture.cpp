/*
===============================================================================

	Giant Leap

	File	:	ScreenTapGesture.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `ScreenTapGesture` class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "TapGestureImplementation.h"
#include "SharedObject.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ScreenTapGesture::ScreenTapGesture()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ScreenTapGesture::ScreenTapGesture( const Gesture &rhs ) : Gesture( rhs )
{
	if( rhs.type() != Gesture::TYPE_SCREEN_TAP )
	{
		// Wrong gesture type. Make this gesture instance invalid.
		m_object->DecrementRefCount();
		m_object = NULL;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector ScreenTapGesture::position() const
{
	return isValid() ? Vector() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector ScreenTapGesture::direction() const
{
	return isValid() ? Vector() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float ScreenTapGesture::progress() const
{
	return isValid() ? 0.0f : 1.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable ScreenTapGesture::pointable() const
{
	return isValid() ? Pointable() : Pointable::invalid();
}