/*
===============================================================================

	Giant Leap

	File	:	FrameImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the real logic behind the `Frame` class.

===============================================================================
*/

#ifndef __FRAMEIMPLEMENTATION_H__
#define __FRAMEIMPLEMENTATION_H__

#include "Network/Buffer.h"

namespace Leap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Frame` class.
	//-------------------------------------------------------------------------
	class FrameImplementation : public Interface::Implementation
	{
	public:
		FrameImplementation();
		FrameImplementation( const Frame &frame );

		// Initialization.
		void				FromLeap( const Frame &frame );

		// Networking.
		BufferWrite			Serialize();
		void				Unserialize( BufferRead *buffer );

		// Manipulations.
		void				Translate( const Vector &v );
		void				Rotate( const Vector &v );

		// Leap interface.
		int64_t				id() const;
		int64_t				timestamp() const;
		InteractionBox		interactionBox() const;
		float				currentFramesPerSecond() const;
		const char *		toCString() const;
		Hand				hand( int32_t id ) const;
		HandList			hands() const;
		Pointable			pointable( int32_t id );
		PointableList		pointables() const;
		Finger				finger( int32_t id ) const;
		FingerList			fingers() const;
		Tool				tool( int32_t id ) const;
		ToolList			tools() const;
		Gesture				gesture( int32_t id ) const;
		GestureList			gestures() const;
		GestureList			gestures( const Frame &sinceFrame ) const;
		Vector				translation( const Frame &sinceFrame ) const;
		float				translationProbability( const Frame &sinceFrame ) const;
		Vector				rotationAxis( const Frame &sinceFrame ) const;
		float				rotationAngle( const Frame &sinceFrame ) const;
		float				rotationAngle( const Frame &sinceFrame, const Vector& axis ) const;
		Matrix				rotationMatrix( const Frame &sinceFrame ) const;
		float				rotationProbability( const Frame &sinceFrame ) const;
		float				scaleFactor( const Frame &sinceFrame ) const;
		float				scaleProbability( const Frame &sinceFrame ) const;

	private:
		int64_t				_id, _timestamp;
	};

}

#endif // __FRAMEIMPLEMENTATION_H__