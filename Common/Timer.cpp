/*
===============================================================================

	Giant Leap

	File	:	Timer.cpp
	Authors	:	Lucas Zadrozny
	Date	:	15th September 2014

	Purpose	:	Defines the timer class.

===============================================================================
*/

#include "Common.h"
#include "Timer.h"
using namespace GiantLeap;

#include <Windows.h>

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct GiantLeap::timeInfo_t
{
	LARGE_INTEGER		_startTime;
	LARGE_INTEGER		_frequency;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Timer::Timer( bool start )
{
	_info = new timeInfo_t;
	QueryPerformanceFrequency( &_info->_frequency );

	if( start )
	{
		Start();
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Timer::~Timer()
{
	delete _info;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT void Timer::Start()
{
	QueryPerformanceCounter( &_info->_startTime );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Timer::Get()
{
	LARGE_INTEGER curTime;

	QueryPerformanceCounter( &curTime );

	return ( curTime.QuadPart - _info->_startTime.QuadPart ) * 1.0f / _info->_frequency.QuadPart;
}