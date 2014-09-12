/*
===============================================================================

	Giant Leap

	File	:	HandImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the real logic behind the `Hand` class.

===============================================================================
*/

#ifndef __HANDIMPLEMENTATION_H__
#define __HANDIMPLEMENTATION_H__

#include "Network/Buffer.h"

namespace Leap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Hand` class.
	//-------------------------------------------------------------------------
	class HandImplementation : public Interface::Implementation
	{
	public:
		HandImplementation();
		HandImplementation( const Leap::Hand &hand );
		HandImplementation( BufferRead *buffer );

		// Initialization.
		void				FromLeap( const Leap::Hand &hand );

		// Networking.
		void				Serialize( BufferWrite *buffer );
		void				Unserialize( BufferRead *buffer );

		// Manipulations.
		void				Translate( const Vector &v );
		void				Rotate( const Vector &v );

		// Leap interface.
		int32_t				id() const;
		Frame				frame() const;
		Vector				palmPosition() const;
		Vector				stabilizedPalmPosition() const;
		Vector				palmVelocity() const;
		Vector				palmNormal() const;
		float				palmWidth() const;
		Vector				direction() const;
		Matrix				basis() const;
		Arm					arm() const;
		Vector				wristPosition() const;
		Vector				sphereCenter() const;
		float				sphereRadius() const;
		float				pinchStrength() const;
		float				grabStrength() const;
		float				timeVisible() const;
		float				confidence() const;
		bool				isLeft() const;
		bool				isRight() const;

		PointableList		pointables() const;
		Pointable			pointable( int32_t id ) const;
		FingerList			fingers() const;
		Finger				finger( int32_t id ) const;
		ToolList			tools() const;
		Tool				tool( int32_t id ) const;

		Vector				translation( const Frame &sinceFrame ) const;
		float				translationProbability( const Frame &sinceFrame ) const;
		Vector				rotationAxis( const Frame &sinceFrame ) const;
		float				rotationAngle( const Frame &sinceFrame ) const;
		float				rotationAngle( const Frame &sinceFrame, const Vector& axis ) const;
		Matrix				rotationMatrix( const Frame &sinceFrame ) const;
		float				rotationProbability( const Frame &sinceFrame ) const;
		float				scaleFactor( const Frame &sinceFrame ) const;
		float				scaleProbability( const Frame &sinceFrame ) const;

		const char *		toCString() const;
	};

}

#endif // __HANDIMPLEMENTATION_H__