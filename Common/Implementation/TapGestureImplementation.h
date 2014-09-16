/*
===============================================================================

	Giant Leap

	File	:	TapGestureImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `KeyTapGesture` class.

===============================================================================
*/

#ifndef __TAPGESTUREIMPLEMENTATION_H__
#define __TAPGESTUREIMPLEMENTATION_H__

#include "GestureImplementation.h"

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `TapGesture` class.
	//-------------------------------------------------------------------------
	class TapGestureImplementation : public GestureImplementation
	{
	public:
		TapGestureImplementation( FrameImplementation &frame );
		TapGestureImplementation( FrameImplementation &frame, const Leap::KeyTapGesture &tap );
		TapGestureImplementation( FrameImplementation &frame, const Leap::ScreenTapGesture &tap );

		// Initialization.
		virtual void		FromLeap( const Leap::KeyTapGesture &tap );
		virtual void		FromLeap( const Leap::ScreenTapGesture &tap );

		// Networking.
		virtual bool		Serialize( BufferWrite *buffer );
		virtual bool		Unserialize( BufferRead *buffer );

		// Manipulations.
		virtual void		Translate( const Vector &v );
		virtual void		Rotate( const Matrix &pry );

		Vector				position() const;
		Vector				direction() const;
		float				progress() const;
		Pointable			pointable() const;

	private:
		Vector				_position;
		Vector				_direction;
		float				_progress;
	};

}

#endif // __TAPGESTUREIMPLEMENTATION_H__