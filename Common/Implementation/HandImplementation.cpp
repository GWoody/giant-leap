/*
===============================================================================

	Giant Leap

	File	:	HandImplementation.cpp
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
HandImplementation::HandImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation::HandImplementation( const Leap::Hand &hand )
{
	FromLeap( hand );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation::HandImplementation( BufferRead *buffer )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::FromLeap( const Leap::Hand &hand )
{
	_id = hand.id();
	_palmPosition = hand.palmPosition();
	_stabilizedPalmPosition = hand.stabilizedPalmPosition();
	_palmVelocity = hand.palmVelocity();
	_palmNormal = hand.palmNormal();
	_palmWidth = hand.palmWidth();
	_direction = hand.direction();
	_sphereCenter = hand.sphereCenter();
	_sphereRadius = hand.sphereRadius();
	_pinchStrength = hand.pinchStrength();
	_grabStrength = hand.grabStrength();
	_confidence = hand.confidence();

	const Leap::FingerList &fingers = hand.fingers();
	for( int i = 0; i < fingers.count(); i++ )
	{
		//FingerImplementation fi( fingers[i] );
		//_fingers.push_back( fi );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::Serialize( BufferWrite *buffer )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::Unserialize( BufferRead *buffer )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::Translate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::Rotate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int32_t HandImplementation::id() const
{
	return _id;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Frame HandImplementation::frame() const
{
	breakpoint();
	return Frame();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::palmPosition() const
{
	return _palmPosition;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::stabilizedPalmPosition() const
{
	return _stabilizedPalmPosition;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::palmVelocity() const
{
	return _palmVelocity;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::palmNormal() const
{
	return _palmNormal;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::palmWidth() const
{
	return _palmWidth;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::direction() const
{
	return _direction;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix HandImplementation::basis() const
{
	breakpoint();
	return Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Arm HandImplementation::arm() const
{
	return Arm( (ArmImplementation *)&_arm );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::wristPosition() const
{
	breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::sphereCenter() const
{
	return _sphereCenter;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::sphereRadius() const
{
	return _sphereRadius;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::pinchStrength() const
{
	return _pinchStrength;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::grabStrength() const
{
	return _grabStrength;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::timeVisible() const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::confidence() const
{
	return _confidence;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::isLeft() const
{
	breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::isRight() const
{
	breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableList HandImplementation::pointables() const
{
	breakpoint();
	return PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable HandImplementation::pointable( int32_t id ) const
{
	breakpoint();
	return Pointable();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerList HandImplementation::fingers() const
{
	return FingerList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Finger HandImplementation::finger( int32_t id ) const
{
	breakpoint();
	return Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ToolList HandImplementation::tools() const
{
	breakpoint();
	return ToolList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Tool HandImplementation::tool( int32_t id ) const
{
	breakpoint();
	return Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::translation( const Frame &sinceFrame ) const
{
	breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::translationProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::rotationAxis( const Frame &sinceFrame ) const
{
	breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationAngle( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationAngle( const Frame &sinceFrame, const Vector& axis ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix HandImplementation::rotationMatrix( const Frame &sinceFrame ) const
{
	breakpoint();
	return Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::scaleFactor( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::scaleProbability( const Frame &sinceFrame ) const
{
	breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char * HandImplementation::toCString() const
{
	breakpoint();
	return "";
}