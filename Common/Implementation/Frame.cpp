/*
===============================================================================

	Giant Leap

	File	:	Frame.cpp
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the Giant Leap version of the `Frame` Leap SDK class.

===============================================================================
*/

#include "GiantLeap.h"
#include "FrameImplementation.h"
#include "SharedObject.h"
using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Frame::Frame( FrameImplementation *ref ) : Interface( ref, ref )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Frame::Frame() : Interface( (SharedObject *)NULL )
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int64_t Frame::id() const
{
	return isValid() ? get<FrameImplementation>()->id() : -1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int64_t Frame::timestamp() const
{
	return isValid() ? get<FrameImplementation>()->timestamp() : 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT HandList Frame::hands() const
{
	return isValid() ? get<FrameImplementation>()->hands() : HandList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Hand Frame::hand( int32_t id ) const
{
	return isValid() ? get<FrameImplementation>()->hand( id ) : Hand();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT PointableList Frame::pointables() const
{
	return isValid() ? get<FrameImplementation>()->pointables() : PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable Frame::pointable( int32_t id ) const
{
	return isValid() ? get<FrameImplementation>()->pointable( id ) : Pointable();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList Frame::fingers() const
{
	return isValid() ? get<FrameImplementation>()->fingers() : FingerList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger Frame::finger( int32_t id ) const
{
	return isValid() ? get<FrameImplementation>()->finger( id ) : Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ToolList Frame::tools() const
{
	return isValid() ? get<FrameImplementation>()->tools() : ToolList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Tool Frame::tool( int32_t id ) const
{
	return isValid() ? get<FrameImplementation>()->tool( id ) : Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GestureList Frame::gestures() const
{
	return isValid() ? get<FrameImplementation>()->gestures() : GestureList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Gesture Frame::gesture( int32_t id ) const
{
	return isValid() ? get<FrameImplementation>()->gesture( id ) : Gesture::invalid();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GestureList Frame::gestures( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->gestures( sinceFrame ) : GestureList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Frame::translation( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->translation( sinceFrame ) : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::translationProbability( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->translationProbability( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Frame::rotationAxis( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->rotationAxis( sinceFrame ) : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::rotationAngle( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->rotationAngle( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::rotationAngle( const Frame& sinceFrame, const Vector& axis ) const
{
	return isValid() ? get<FrameImplementation>()->rotationAngle( sinceFrame, axis ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Matrix Frame::rotationMatrix( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->rotationMatrix( sinceFrame ) : Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::rotationProbability( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->rotationProbability( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::scaleFactor( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->scaleFactor( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::scaleProbability( const Frame& sinceFrame ) const
{
	return isValid() ? get<FrameImplementation>()->scaleProbability( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT InteractionBox Frame::interactionBox() const
{
	return isValid() ? get<FrameImplementation>()->interactionBox() : InteractionBox::invalid();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::currentFramesPerSecond() const
{
	return isValid() ? get<FrameImplementation>()->currentFramesPerSecond() : 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Frame::isValid() const
{
	return get<FrameImplementation>() != NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const Frame &Frame::invalid()
{
	static Frame invalid( NULL );
	return invalid;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Frame::operator==( const Frame &other ) const
{
	return get<FrameImplementation>() == other.get<FrameImplementation>();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Frame::operator!=( const Frame &other ) const
{
	return get<FrameImplementation>() != other.get<FrameImplementation>();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const char *Frame::toCString() const
{
	return isValid() ? get<FrameImplementation>()->toCString() : "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT std::ostream &operator<<( std::ostream &out, Frame &f )
{
	out << f.toString();
	return out;
}