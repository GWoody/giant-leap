/*
===============================================================================

	Giant Leap

	File	:	Finger.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `Finger` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "FingerImplementation.h"
#include "SharedObject.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger::Finger() : Pointable( (PointableImplementation *)NULL )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Finger::Finger( FingerImplementation *finger ) : Pointable( finger )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger::Finger( const Pointable &pointable ) : Pointable( pointable )
{
	if( isValid() && !pointable.isFinger() )
	{
		m_object->DecrementRefCount();
		m_object = NULL;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Bone Finger::bone( Bone::Type idx ) const
{
	return isValid() ? get<FingerImplementation>()->bone( idx ) : Bone();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger::Type Finger::type() const
{
	return isValid() ? get<FingerImplementation>()->type() : Finger::Type::TYPE_THUMB;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const char *Finger::toCString() const
{
	return isValid() ? get<FingerImplementation>()->toCString() : "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const Finger &Finger::invalid()
{
	static Finger f( NULL );
	return f;
}