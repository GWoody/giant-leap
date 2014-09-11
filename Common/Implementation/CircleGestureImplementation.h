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

namespace Leap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `CircleGesture` class.
	//-------------------------------------------------------------------------
	class CircleGestureImplementation : public Interface::Implementation
	{
	public:
		CircleGestureImplementation();

		Vector				center() const;
		Vector				normal() const;
		float				progress() const;
		float				radius() const;
		Pointable			pointable() const;
	};

}

#endif // __CIRCLEGESTUREIMPLEMENTATION_H__