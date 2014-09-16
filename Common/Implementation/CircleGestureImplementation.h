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
		CircleGestureImplementation( FrameImplementation &frame );
		CircleGestureImplementation( FrameImplementation &frame, const Leap::CircleGesture &circle );

		// Initialization.
		virtual void		FromLeap( const Leap::CircleGesture &circle );

		// Networking.
		virtual bool		Serialize( BufferWrite *buffer );
		virtual bool		Unserialize( BufferRead *buffer );

		// Manipulations.
		virtual void		Translate( const Vector &v );
		virtual void		Rotate( const Matrix &pry );

		Vector				center() const;
		Vector				normal() const;
		float				progress() const;
		float				radius() const;
		Pointable			pointable() const;

	private:
		int32_t				_pointableId;
		Vector				_center;
		Vector				_normal;
		float				_progress;
		float				_radius;
	};

}

#endif // __CIRCLEGESTUREIMPLEMENTATION_H__