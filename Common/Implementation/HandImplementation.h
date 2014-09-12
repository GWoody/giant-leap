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
#include "FingerImplementation.h"
#include "ArmImplementation.h"
#include <vector>

namespace GiantLeap
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
		bool				Serialize( BufferWrite *buffer );
		bool				Unserialize( BufferRead *buffer );

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

	private:
		int32_t				_id;

		std::vector<FingerImplementation>	_fingers;
		ArmImplementation	_arm;

		Vector				_palmPosition;
		Vector				_stabilizedPalmPosition;
		Vector				_palmVelocity;
		Vector				_palmNormal;
		float				_palmWidth;
		Vector				_direction;
		Vector				_sphereCenter;
		float				_sphereRadius;
		float				_pinchStrength;
		float				_grabStrength;
		float				_confidence;
	};

}

#endif // __HANDIMPLEMENTATION_H__