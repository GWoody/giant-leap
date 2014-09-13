/*
===============================================================================

	Giant Leap

	File	:	Tool.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	##### DO NOT IMPLEMENT!!! #####

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
LEAP_EXPORT Tool::Tool() : Pointable( (PointableImplementation *)NULL )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Tool::Tool( ToolImplementation *finger ) : Pointable( finger )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Tool::Tool( const Pointable &pointable ) : Pointable( pointable )
{
	if( !pointable.isFinger() )
	{
		m_object->DecrementRefCount();
		m_object = NULL;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const Tool &Tool::invalid()
{
	static Tool t;
	return t;
}