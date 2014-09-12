/*
===============================================================================

	Giant Leap

	File	:	CircleGestureImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `CircleGesture` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "CircleGestureImplementation.h"
using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CircleGestureImplementation::CircleGestureImplementation()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Leap::Vector CircleGestureImplementation::center() const
{
	return Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Leap::Vector CircleGestureImplementation::normal() const
{
	return Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float CircleGestureImplementation::progress() const
{
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float CircleGestureImplementation::radius() const
{
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable CircleGestureImplementation::pointable() const
{
	breakpoint();
	return Pointable();
}