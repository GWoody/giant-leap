/*
===============================================================================

	Giant Leap

	File	:	CircleGestureImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the real logic behind the `CircleGesture` class.

===============================================================================
*/

#ifndef __CIRCLEGESTUREIMPLEMENTATION_H__
#define __CIRCLEGESTUREIMPLEMENTATION_H__

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `CircleGesture` class.
	//-------------------------------------------------------------------------
	class CircleGestureImplementation : public Interface::Implementation
	{
	public:
		CircleGestureImplementation();

		Leap::Vector				center() const;
		Leap::Vector				normal() const;
		float				progress() const;
		float				radius() const;
		Pointable			pointable() const;
	};

}

#endif // __CIRCLEGESTUREIMPLEMENTATION_H__