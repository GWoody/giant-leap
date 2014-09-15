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
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

//-----------------------------------------------------------------------------
// Interface->Implementation pairing.
//-----------------------------------------------------------------------------
#include "Pair.h"

namespace GiantLeap
{
	typedef Pair<Gesture, GestureImplementation>		GesturePair_t;
	typedef Pair<Arm, ArmImplementation>				ArmPair_t;
	typedef Pair<Bone, BoneImplementation>				BonePair_t;
	typedef Pair<Hand, HandImplementation>				HandPair_t;
	typedef Pair<Finger, FingerImplementation>			FingerPair_t;
	typedef Pair<Pointable, PointableImplementation>	PointablePair_t;
	typedef Pair<Frame, FrameImplementation>			FramePair_t;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define C_breakpoint()				__asm { int 3 }
#define C_clamp( var, min, max )	( ( (var) < (min) ) ? (min) : ( ( (var) > (max) ) ? (max) : (var) ) )

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GiantLeap::Vector string_to_vector( const std::string &str );

#endif // __COMMON_H__