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

#include "GestureImplementation.h"

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `CircleGesture` class.
	//-------------------------------------------------------------------------
	class CircleGestureImplementation : public GestureImplementation
	{
	public:
		CircleGestureImplementation();
		CircleGestureImplementation( const Leap::CircleGesture &circle );

		// Initialization.
		void				FromLeap( const Leap::CircleGesture &circle );

		// Networking.
		bool				Serialize( BufferWrite *buffer );
		bool				Unserialize( BufferRead *buffer );

		// Manipulations.
		void				Translate( const Vector &v );
		void				Rotate( const Vector &v );

		Vector				center() const;
		Vector				normal() const;
		float				progress() const;
		float				radius() const;
		Pointable			pointable() const;

	private:
		Vector				_center;
		Vector				_normal;
		float				_progress;
		float				_radius;
	};

}

#endif // __CIRCLEGESTUREIMPLEMENTATION_H__