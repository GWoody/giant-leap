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

#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define C_breakpoint()				__asm { int 3 }
#define C_clamp( var, min, max )	( ( (var) < (min) ) ? (min) : ( ( (var) > (max) ) ? (max) : (var) ) )

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GiantLeap::Vector string_to_vector( const std::string &str );

#endif // __COMMON_H__