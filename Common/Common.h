/*
===============================================================================

	Giant Leap

	File	:	Common.h
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Shared common module definitions.

===============================================================================
*/

#ifndef __COMMON_H__
#define __COMMON_H__

#include <string>
#include "GiantLeap.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define breakpoint()			__asm { int 3 }

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GiantLeap::Vector string_to_vector( const std::string &str );

#endif // __COMMON_H__