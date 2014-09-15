/*
===============================================================================

	Giant Leap

	File	:	TimerUnit.cpp
	Authors	:	Lucas Zadrozny
	Date	:   15th September 2014

	Purpose	:	Implements the `Timer` test cases

===============================================================================
*/

#include "Common.h"
#include "CommonUnit.h"

#include <Windows.h>

#include <iostream>
using namespace std;

#include "GiantLeap.h"
#include "Timer.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool run_timer_test()
{
	Timer t( true );
	Sleep( 500 );

	float time = t.Get();
	ASSERT( "Checking timer is ( 0.5 +- 0.01 )", time > 0.49f && time < 0.51f );

	return true;
}