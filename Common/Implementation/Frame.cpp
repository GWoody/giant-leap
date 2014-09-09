/*
===============================================================================

	Giant Leap

	File	:	Frame.cpp
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the Giant Leap version of the `Frame` Leap SDK class.

===============================================================================
*/

#include "Leap.h"
#include "FrameImplementation.h"
#include "SharedObject.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Frame::Frame( FrameImplementation *ref ) : Interface( ref, this )
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
	return get<FrameImplementation>()->id();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int64_t Frame::timestamp() const
{
	return get<FrameImplementation>()->timestamp();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT HandList Frame::hands() const
{
	return get<FrameImplementation>()->hands();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Hand Frame::hand( int32_t id ) const
{
	return get<FrameImplementation>()->hand( id );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT PointableList Frame::pointables() const
{
	return get<FrameImplementation>()->pointables();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable Frame::pointable( int32_t id ) const
{
	return get<FrameImplementation>()->pointable( id );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList Frame::fingers() const
{
	return get<FrameImplementation>()->fingers();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger Frame::finger( int32_t id ) const
{
	return get<FrameImplementation>()->finger( id );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ToolList Frame::tools() const
{
	return get<FrameImplementation>()->tools();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Tool Frame::tool( int32_t id ) const
{
	return get<FrameImplementation>()->tool( id );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GestureList Frame::gestures() const
{
	return get<FrameImplementation>()->gestures();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Gesture Frame::gesture( int32_t id ) const
{
	return get<FrameImplementation>()->gesture( id );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GestureList Frame::gestures( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->gestures( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Frame::translation( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->translation( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::translationProbability( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->translationProbability( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Frame::rotationAxis( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->rotationAxis( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::rotationAngle( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->rotationAngle( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::rotationAngle( const Frame& sinceFrame, const Vector& axis ) const
{
	return get<FrameImplementation>()->rotationAngle( sinceFrame, axis );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Matrix Frame::rotationMatrix( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->rotationMatrix( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::rotationProbability( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->rotationProbability( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::scaleFactor( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->scaleFactor( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::scaleProbability( const Frame& sinceFrame ) const
{
	return get<FrameImplementation>()->scaleProbability( sinceFrame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT InteractionBox Frame::interactionBox() const
{
	return get<FrameImplementation>()->interactionBox();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Frame::currentFramesPerSecond() const
{
	return get<FrameImplementation>()->currentFramesPerSecond();
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
	return get<FrameImplementation>()->toCString();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT std::ostream &operator<<( std::ostream &out, Frame &f )
{
	out << f.toString();
	return out;
}