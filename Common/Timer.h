/*
===============================================================================

	Giant Leap

	File	:	Timer.h
	Authors	:	Lucas Zadrozny
	Date	:	15th September 2014

	Purpose	:	Defines the timer class.

===============================================================================
*/

#ifndef __TIMER_H__
#define __TIMER_H__

#include "GiantLeap.h"

namespace GiantLeap
{

	struct timeInfo_t;

	//-------------------------------------------------------------------------
	// Note: The implementation object MUST ALWAYS be allocated on the heap.
	//-------------------------------------------------------------------------
	class Timer
	{
	public:
		LEAP_EXPORT Timer( bool start );
		LEAP_EXPORT ~Timer();

		LEAP_EXPORT void	Start();
		LEAP_EXPORT float	Get();

	private:
		timeInfo_t *		_info;
	};

}

#endif // __TIMER_H__