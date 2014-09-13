/*
===============================================================================

	Giant Leap

	File	:	TapGestureImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `TapGesture` class.

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
TapGestureImplementation::TapGestureImplementation()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector TapGestureImplementation::position() const
{
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector TapGestureImplementation::direction() const
{
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float TapGestureImplementation::progress() const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable TapGestureImplementation::pointable() const
{
	C_breakpoint();
	return Pointable();
}