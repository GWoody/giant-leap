/*
===============================================================================

	Giant Leap

	File	:	SwipeGestureImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the real logic behind the `SwipeGesture` class.

===============================================================================
*/

#ifndef __SWIPEGESTUREIMPLEMENTATION_H__
#define __SWIPEGESTUREIMPLEMENTATION_H__

#include "GestureImplementation.h"

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Pointable` class.
	//-------------------------------------------------------------------------
	class SwipeGestureImplementation : public GestureImplementation
	{
	public:
		SwipeGestureImplementation( FrameImplementation &frame );
		SwipeGestureImplementation( FrameImplementation &frame, const Leap::SwipeGesture &swipe );

		// Initialization.
		virtual void		FromLeap( const Leap::SwipeGesture &swipe );

		// Networking.
		virtual bool		Serialize( BufferWrite *buffer );
		virtual bool		Unserialize( BufferRead *buffer );

		// Manipulations.
		virtual void		Translate( const Vector &v );
		virtual void		Rotate( const Vector &v );

		Vector				startPosition() const;
		Vector				position() const;
		Vector				direction() const;
		float				speed() const;
		Pointable			pointable() const;

	private:
		Vector				_startPosition;
		Vector				_position;
		Vector				_direction;
		float				_speed;
	};

}

#endif // __SWIPEGESTUREIMPLEMENTATION_H__