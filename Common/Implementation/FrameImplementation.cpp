/*
===============================================================================

	Giant Leap

	File	:	FrameImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the actual logic behind the `Frame` class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "FrameImplementation.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation::FrameImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation::FrameImplementation( const Frame &frame )
{
	FromLeap( frame );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::FromLeap( const Frame &frame )
{
	const HandList &hands = frame.hands();
	const GestureList &gestures = frame.gestures();

	_id = frame.id();
	_timestamp = frame.timestamp();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BufferWrite FrameImplementation::Serialize()
{
	BufferWrite buf;

	buf.Write( &_id, sizeof(_id) );
	buf.Write( &_timestamp, sizeof(_timestamp) );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Unserialize( BufferRead *buffer )
{
	_id = buffer->ReadLongLong();
	_timestamp = buffer->ReadLongLong();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Translate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FrameImplementation::Rotate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int64_t FrameImplementation::id() const
{
	return _id;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int64_t FrameImplementation::timestamp() const
{
	return _timestamp;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
InteractionBox FrameImplementation::interactionBox() const
{
	breakpoint();
	return InteractionBox();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::currentFramesPerSecond() const
{
	return 60.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char *FrameImplementation::toCString() const
{
	breakpoint();
	return "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandList FrameImplementation::hands() const
{
	return HandList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableList FrameImplementation::pointables() const
{
	breakpoint();
	return PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerList FrameImplementation::fingers() const
{
	breakpoint();
	return FingerList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ToolList FrameImplementation::tools() const
{
	breakpoint();
	return ToolList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureList FrameImplementation::gestures() const
{
	return GestureList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Hand FrameImplementation::hand( int32_t id ) const
{
	return Hand();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable FrameImplementation::pointable( int32_t id )
{
	breakpoint();
	return Pointable();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Finger FrameImplementation::finger( int32_t id ) const
{
	breakpoint();
	return Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Tool FrameImplementation::tool( int32_t id ) const
{
	breakpoint();
	return Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Gesture FrameImplementation::gesture( int32_t id ) const
{
	return Gesture();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureList FrameImplementation::gestures( const Frame &sinceFrame ) const
{
	return GestureList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector FrameImplementation::translation( const Frame &sinceFrame ) const
{
	breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::translationProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector FrameImplementation::rotationAxis( const Frame &sinceFrame ) const
{
	breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationAngle( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationAngle( const Frame &sinceFrame, const Vector& axis ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix FrameImplementation::rotationMatrix( const Frame &sinceFrame ) const
{
	breakpoint();
	return Matrix();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::rotationProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::scaleFactor( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float FrameImplementation::scaleProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}