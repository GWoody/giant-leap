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

namespace Leap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Frame` class.
	//-------------------------------------------------------------------------
	class FrameImplementation : public Interface::Implementation
	{
	public:
		FrameImplementation();

		int64_t				id() const;
		int64_t				timestamp() const;
		InteractionBox		interactionBox() const;
		float				currentFramesPerSecond() const;
		const char *		toCString() const;

		HandList			hands() const;
		PointableList		pointables() const;
		FingerList			fingers() const;
		ToolList			tools() const;
		GestureList			gestures() const;

		Hand				hand( int32_t id ) const;
		Pointable			pointable( int32_t id );
		Finger				finger( int32_t id ) const;
		Tool				tool( int32_t id ) const;
		Gesture				gesture( int32_t id ) const;

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
	};

}

#endif // __FRAMEIMPLEMENTATION_H__