/*
===============================================================================

	Giant Leap

	File	:	ControllerImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the actual logic behind the `Controller` class.

===============================================================================
*/

#include "Leap.h"
#include "ControllerImplementation.h"

using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::isConnected() const
{
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::isServiceConnected() const
{
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::hasFocus() const
{
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Controller::PolicyFlag ControllerImplementation::policyFlags() const
{
	return Controller::POLICY_DEFAULT;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ControllerImplementation::setPolicyFlags( Controller::PolicyFlag flags )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::addListener( Listener &listener )
{
	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::removeListener( Listener &listener )
{
	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ControllerImplementation::enableGesture( Gesture::Type type, bool enable )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::isGestureEnabled( Gesture::Type type )
{
	return true;
}