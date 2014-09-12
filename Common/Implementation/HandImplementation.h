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
		void				Serialize( BufferWrite *buffer );
		void				Unserialize( BufferRead *buffer );

		// Manipulations.
		void				Translate( const Leap::Vector &v );
		void				Rotate( const Leap::Vector &v );

		// Leap interface.
		int32_t				id() const;
		Frame				frame() const;
		Leap::Vector				palmPosition() const;
		Leap::Vector				stabilizedPalmPosition() const;
		Leap::Vector				palmVelocity() const;
		Leap::Vector				palmNormal() const;
		float				palmWidth() const;
		Leap::Vector				direction() const;
		Leap::Matrix				basis() const;
		Arm					arm() const;
		Leap::Vector				wristPosition() const;
		Leap::Vector				sphereCenter() const;
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

		Leap::Vector				translation( const Frame &sinceFrame ) const;
		float				translationProbability( const Frame &sinceFrame ) const;
		Leap::Vector				rotationAxis( const Frame &sinceFrame ) const;
		float				rotationAngle( const Frame &sinceFrame ) const;
		float				rotationAngle( const Frame &sinceFrame, const Leap::Vector& axis ) const;
		Leap::Matrix				rotationMatrix( const Frame &sinceFrame ) const;
		float				rotationProbability( const Frame &sinceFrame ) const;
		float				scaleFactor( const Frame &sinceFrame ) const;
		float				scaleProbability( const Frame &sinceFrame ) const;

		const char *		toCString() const;

	private:
		int32_t				_id;

		std::vector<FingerImplementation>	_fingers;
		ArmImplementation	_arm;

		Leap::Vector				_palmPosition;
		Leap::Vector				_stabilizedPalmPosition;
		Leap::Vector				_palmVelocity;
		Leap::Vector				_palmNormal;
		float				_palmWidth;
		Leap::Vector				_direction;
		Leap::Vector				_sphereCenter;
		float				_sphereRadius;
		float				_pinchStrength;
		float				_grabStrength;
		float				_confidence;
	};

}

#endif // __HANDIMPLEMENTATION_H__