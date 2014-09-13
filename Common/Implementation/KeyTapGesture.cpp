/*
===============================================================================

	Giant Leap

	File	:	KeyTapGesture.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `KeyTapGesture` class.

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
LEAP_EXPORT KeyTapGesture::KeyTapGesture()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT KeyTapGesture::KeyTapGesture( const Gesture &rhs ) : Gesture( rhs )
{
	if( rhs.type() != Gesture::TYPE_KEY_TAP )
	{
		// Wrong gesture type. Make this gesture instance invalid.
		m_object->DecrementRefCount();
		m_object = NULL;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector KeyTapGesture::position() const
{
	return isValid() ? Vector() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector KeyTapGesture::direction() const
{
	return isValid() ? Vector() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float KeyTapGesture::progress() const
{
	return isValid() ? 0.0f : 1.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable KeyTapGesture::pointable() const
{
	return isValid() ? Pointable() : Pointable::invalid();
}