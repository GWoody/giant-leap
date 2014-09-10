/*
===============================================================================

	Giant Leap

	File	:	InteractionBox.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	##### DO NOT IMPLEMENT!!! #####

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT InteractionBox::InteractionBox() : Interface( (SharedObject *) NULL )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const InteractionBox &InteractionBox::invalid()
{
	static InteractionBox b;
	return b;
}