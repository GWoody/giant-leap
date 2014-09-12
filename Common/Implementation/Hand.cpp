/*
===============================================================================

	Giant Leap

	File	:	Hand.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `Hand` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "HandImplementation.h"
using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Hand::Hand() : Interface( (SharedObject *) NULL )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Hand::Hand( HandImplementation *ref ) : Interface( ref, this )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int32_t Hand::id() const
{
	return isValid() ? get<HandImplementation>()->id() : -1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Frame Hand::frame() const
{
	return isValid() ? get<HandImplementation>()->frame() : Frame();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::palmPosition() const
{
	return isValid() ? get<HandImplementation>()->palmPosition() : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::stabilizedPalmPosition() const
{
	return isValid() ? get<HandImplementation>()->stabilizedPalmPosition() : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::palmVelocity() const
{
	return isValid() ? get<HandImplementation>()->palmVelocity() : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::palmNormal() const
{
	return isValid() ? get<HandImplementation>()->palmNormal() : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::palmWidth() const
{
	return isValid() ? get<HandImplementation>()->palmWidth() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::direction() const
{
	return isValid() ? get<HandImplementation>()->direction() : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Matrix Hand::basis() const
{
	return isValid() ? get<HandImplementation>()->basis() : Leap::Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Arm Hand::arm() const
{
	return isValid() ? get<HandImplementation>()->arm() : Arm();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::wristPosition() const
{
	return isValid() ? get<HandImplementation>()->wristPosition() : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::sphereCenter() const
{
	return isValid() ? get<HandImplementation>()->sphereCenter() : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::sphereRadius() const
{
	return isValid() ? get<HandImplementation>()->sphereRadius() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::pinchStrength() const
{
	return isValid() ? get<HandImplementation>()->pinchStrength() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::grabStrength() const
{
	return isValid() ? get<HandImplementation>()->grabStrength() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::timeVisible() const
{
	return isValid() ? get<HandImplementation>()->timeVisible() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::confidence() const
{
	return isValid() ? get<HandImplementation>()->confidence() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Hand::isLeft() const
{
	return isValid() ? get<HandImplementation>()->isLeft() : false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Hand::isRight() const
{
	return isValid() ? get<HandImplementation>()->isRight() : false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT PointableList Hand::pointables() const
{
	return isValid() ? get<HandImplementation>()->pointables() : PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Pointable Hand::pointable( int32_t id ) const
{
	return isValid() ? get<HandImplementation>()->pointable( id ) : Pointable();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList Hand::fingers() const
{
	return isValid() ? get<HandImplementation>()->fingers() : FingerList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger Hand::finger( int32_t id ) const
{
	return isValid() ? get<HandImplementation>()->finger( id ) : Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ToolList Hand::tools() const
{
	return isValid() ? get<HandImplementation>()->tools() : ToolList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Tool Hand::tool( int32_t id ) const
{
	return isValid() ? get<HandImplementation>()->tool( id ) : Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::translation( const Frame &sinceFrame ) const
{
	return isValid() ? get<HandImplementation>()->translation( sinceFrame ) : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::translationProbability( const Frame &sinceFrame ) const
{
	return isValid() ? get<HandImplementation>()->translationProbability( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Vector Hand::rotationAxis( const Frame &sinceFrame ) const
{
	return isValid() ? get<HandImplementation>()->rotationAxis( sinceFrame ) : Leap::Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::rotationAngle( const Frame &sinceFrame ) const
{
	return isValid() ? get<HandImplementation>()->rotationAngle( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::rotationAngle( const Frame &sinceFrame, const Leap::Vector& axis ) const
{
	return isValid() ? get<HandImplementation>()->rotationAngle( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Leap::Matrix Hand::rotationMatrix( const Frame &sinceFrame ) const
{
	return isValid() ? get<HandImplementation>()->rotationMatrix( sinceFrame ) : Leap::Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::rotationProbability( const Frame &sinceFrame ) const
{
	return isValid() ? get<HandImplementation>()->rotationProbability( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::scaleFactor( const Frame &sinceFrame ) const
{
	return isValid() ? get<HandImplementation>()->scaleFactor( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Hand::scaleProbability( const Frame &sinceFrame ) const
{
	return isValid() ? get<HandImplementation>()->scaleProbability( sinceFrame ) : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const char * Hand::toCString() const
{
	return isValid() ? get<HandImplementation>()->toCString() : "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const Hand &Hand::invalid()
{
	static Hand h;
	return h;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Hand::isValid() const
{
	return get<HandImplementation>() != NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Hand::operator==( const Hand &other ) const
{
	return get<HandImplementation>() == other.get<HandImplementation>();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Hand::operator!=( const Hand &other ) const
{
	return get<HandImplementation>() != other.get<HandImplementation>();
}