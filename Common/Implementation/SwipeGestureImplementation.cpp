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
Vector SwipeGestureImplementation::startPosition() const
{
	return Vector();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector SwipeGestureImplementation::position() const
{
	return Vector();	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector SwipeGestureImplementation::direction() const
{
	return Vector();	
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