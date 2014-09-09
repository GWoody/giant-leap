/*
===============================================================================

	Giant Leap

	File	:	GestureImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the real logic behind the `Gesture` class.

===============================================================================
*/

#ifndef __GESTUREIMPLEMENTATION_H__
#define __GESTUREIMPLEMENTATION_H__

namespace Leap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Gesture` class.
	//-------------------------------------------------------------------------
	class GestureImplementation : public Interface::Implementation
	{
	public:
		GestureImplementation();

		int32_t				id() const;
		Gesture::Type		type() const;
		Gesture::State		state() const;
		int64_t				duration() const;
		float				durationSeconds() const;
		Frame				frame() const;
		HandList			hands() const;
		PointableList		pointables() const;
		
		const char *		toCString() const;
	};

}

#endif // __GESTUREIMPLEMENTATION_H__