/*
===============================================================================

	Giant Leap

	File	:	SwipeGestureImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the real logic behind the `SwipeGesture` class.

===============================================================================
*/

#ifndef __POINTABLEIMPLEMENTATION_H__
#define __POINTABLEIMPLEMENTATION_H__

#include "GestureImplementation.h"

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Pointable` class.
	//-------------------------------------------------------------------------
	class SwipeGestureImplementation : public GestureImplementation
	{
	public:
		SwipeGestureImplementation();

		Vector				startPosition() const;
		Vector				position() const;
		Vector				direction() const;
		float				speed() const;
		Pointable			pointable() const;
	};

}

#endif // __POINTABLEIMPLEMENTATION_H__