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
		TapGestureImplementation();
		TapGestureImplementation( const Leap::KeyTapGesture &tap );
		TapGestureImplementation( const Leap::ScreenTapGesture &tap );

		// Initialization.
		void				FromLeap( const Leap::KeyTapGesture &tap );
		void				FromLeap( const Leap::ScreenTapGesture &tap );

		// Networking.
		bool				Serialize( BufferWrite *buffer );
		bool				Unserialize( BufferRead *buffer );

		// Manipulations.
		void				Translate( const Vector &v );
		void				Rotate( const Vector &v );

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