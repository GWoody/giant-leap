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
SwipeGestureImplementation::SwipeGestureImplementation()
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Leap::Vector SwipeGestureImplementation::startPosition() const
{
	return Leap::Vector();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Leap::Vector SwipeGestureImplementation::position() const
{
	return Leap::Vector();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Leap::Vector SwipeGestureImplementation::direction() const
{
	return Leap::Vector();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float SwipeGestureImplementation::speed() const
{
	return 0.0f;	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable SwipeGestureImplementation::pointable() const
{
	return Pointable();	
}