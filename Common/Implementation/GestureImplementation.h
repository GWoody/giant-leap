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
#include "Pair.h"

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Gesture` class.
	//-------------------------------------------------------------------------
	class GestureImplementation : public Interface::Implementation
	{
	public:
		static GestureImplementation *	Create( FrameImplementation &frame, const Leap::Gesture &gesture );
		static GestureImplementation *	Create( FrameImplementation &frame, Gesture::Type type );

		GestureImplementation( FrameImplementation &frame );
		GestureImplementation( FrameImplementation &frame, const Leap::Gesture &gesture );

		// Initialization.
		virtual void		FromLeap( const Leap::Gesture &gesture );

		// Networking.
		virtual bool		Serialize( BufferWrite *buffer );
		virtual bool		Unserialize( BufferRead *buffer );

		// Manipulations.
		virtual void		Translate( const Vector &v );
		virtual void		Rotate( const Matrix &pry );

		int32_t				id() const;
		Gesture::Type		type() const;
		Gesture::State		state() const;
		int64_t				duration() const;
		float				durationSeconds() const;
		Frame				frame() const;
		HandList			hands() const;
		PointableList		pointables() const;
		
		const char *		toCString() const;

		const std::vector<int32_t> &	handIds() const;

	protected:
		FrameImplementation &	_frame;

	private:
		int32_t				_id;
		Gesture::Type		_type;
		int64_t				_duration;
		float				_durationSeconds;
		bool				_clockwise;

		std::vector<int32_t>	_handIds;
	};

}

#endif // __GESTUREIMPLEMENTATION_H__