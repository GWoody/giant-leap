/*
===============================================================================

	Giant Leap

	File	:	PointableImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `Pointable` class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "PointableImplementation.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableImplementation::PointableImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int32_t PointableImplementation::id() const
{
	return -1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Frame PointableImplementation::frame() const
{
	breakpoint();
	return Frame();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Hand PointableImplementation::hand() const
{
	breakpoint();
	return Hand::invalid();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector PointableImplementation::tipPosition() const
{
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector PointableImplementation::stabilizedTipPosition() const
{
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector PointableImplementation::tipVelocity() const
{
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector PointableImplementation::direction() const
{
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float PointableImplementation::width() const
{
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float PointableImplementation::length() const
{
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float PointableImplementation::timeVisible() const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool PointableImplementation::isFinger() const
{
	breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool PointableImplementation::isTool() const
{
	breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool PointableImplementation::isExtended() const
{
	breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable::Zone PointableImplementation::touchZone() const
{
	breakpoint();
	return Pointable::Zone();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float PointableImplementation::touchDistance() const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char *PointableImplementation::toCString() const
{
	breakpoint();
	return "";
}