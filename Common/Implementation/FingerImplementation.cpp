/*
===============================================================================

	Giant Leap

	File	:	FingerImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `Finger` class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "FingerImplementation.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerImplementation::FingerImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Bone FingerImplementation::bone( Bone::Type idx ) const
{
	return Bone();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Finger::Type FingerImplementation::type() const
{
	return Finger::Type::TYPE_THUMB;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char *FingerImplementation::toCString() const
{
	breakpoint();
	return "";
}