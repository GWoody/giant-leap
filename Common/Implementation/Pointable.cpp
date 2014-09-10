/*
===============================================================================

	Giant Leap

	File	:	Pointable.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `Pointable` class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "PointableImplementation.h"
#include "FingerImplementation.h"
#include "SharedObject.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable::Pointable( PointableImplementation *ref ) : Interface( ref, this )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable::Pointable( FingerImplementation *ref ) : Interface( ref, this )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable::Pointable( ToolImplementation *ref ) : Interface( NULL, this )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable::Pointable() : Interface( (SharedObject *)NULL )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int32_t Pointable::id() const
{
	return isValid() ? get<PointableImplementation>()->id() : -1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Frame Pointable::frame() const
{
	return isValid() ? get<PointableImplementation>()->frame() : Frame();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Hand Pointable::hand() const
{
	return isValid() ? get<PointableImplementation>()->hand() : Hand();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Pointable::tipPosition() const
{
	return isValid() ? get<PointableImplementation>()->tipPosition() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Pointable::stabilizedTipPosition() const
{
	return isValid() ? get<PointableImplementation>()->stabilizedTipPosition() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Pointable::tipVelocity() const
{
	return isValid() ? get<PointableImplementation>()->tipVelocity() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Pointable::direction() const
{
	return isValid() ? get<PointableImplementation>()->direction() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Pointable::width() const
{
	return isValid() ? get<PointableImplementation>()->width() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Pointable::length() const
{
	return isValid() ? get<PointableImplementation>()->length() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Pointable::timeVisible() const
{
	return isValid() ? get<PointableImplementation>()->timeVisible() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Pointable::isFinger() const
{
	return isValid() ? get<PointableImplementation>()->isFinger() : false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Pointable::isTool() const
{
	return isValid() ? get<PointableImplementation>()->isTool() : false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Pointable::isExtended() const
{
	return isValid() ? get<PointableImplementation>()->isExtended() : false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Pointable::isValid() const
{
	return get<PointableImplementation>() != NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable::Zone Pointable::touchZone() const
{
	return isValid() ? get<PointableImplementation>()->touchZone() : Pointable::Zone();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Pointable::touchDistance() const
{
	return isValid() ? get<PointableImplementation>()->touchDistance() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const char *Pointable::toCString() const
{
	return isValid() ? get<PointableImplementation>()->toCString() : "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const Pointable &Pointable::invalid()
{
	static Pointable p;
	return p;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Pointable::operator==( const Pointable &other ) const
{
	return get<PointableImplementation>() == other.get<PointableImplementation>();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Pointable::operator!=( const Pointable &other ) const
{
	return get<PointableImplementation>() != other.get<PointableImplementation>();
}