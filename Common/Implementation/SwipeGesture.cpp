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

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT SwipeGesture::SwipeGesture()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT SwipeGesture::SwipeGesture( const Gesture &rhs ) : Gesture( rhs )
{
	if( rhs.type() != Gesture::TYPE_SWIPE )
	{
		// Wrong gesture type. Make this gesture instance invalid.
		m_object->DecrementRefCount();
		m_object = NULL;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector SwipeGesture::startPosition() const
{
	return Leap::Vector();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector SwipeGesture::position() const
{
	return Leap::Vector();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector SwipeGesture::direction() const
{
	return Leap::Vector();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float SwipeGesture::speed() const
{
	return 0.0f;	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable SwipeGesture::pointable() const
{
	return Pointable();	
}