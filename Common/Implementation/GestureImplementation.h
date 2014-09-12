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

#include "Network/Buffer.h"

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Gesture` class.
	//-------------------------------------------------------------------------
	class GestureImplementation : public Interface::Implementation
	{
	public:
		GestureImplementation();
		GestureImplementation( const Leap::Gesture &gesture );
		GestureImplementation( BufferRead *buffer );

		// Initialization.
		void				FromLeap( const Leap::Gesture &gesture );

		// Networking.
		void				Serialize( BufferWrite *buffer );
		void				Unserialize( BufferRead *buffer );

		// Manipulations.
		void				Translate( const Vector &v );
		void				Rotate( const Vector &v );

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