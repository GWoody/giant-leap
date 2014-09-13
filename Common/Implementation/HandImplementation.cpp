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

#include "MemDebugOn.h"

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
		FingerImplementation fi( fingers[i] );
		_fingers.push_back( fi );
	}

	_arm.FromLeap( hand.arm() );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'hand' );

	buffer->WriteInt( _id );
	buffer->WriteVector( _palmPosition );
	buffer->WriteVector( _stabilizedPalmPosition );
	buffer->WriteVector( _palmVelocity );
	buffer->WriteVector( _palmNormal );
	buffer->WriteFloat( _palmWidth );
	buffer->WriteVector( _direction );
	buffer->WriteVector( _sphereCenter );
	buffer->WriteFloat( _sphereRadius );
	buffer->WriteFloat( _pinchStrength );
	buffer->WriteFloat( _grabStrength );
	buffer->WriteFloat( _confidence );

	buffer->WriteInt( _fingers.size() );
	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		_fingers[i].Serialize( buffer );
	}

	_arm.Serialize( buffer );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::Unserialize( BufferRead *buffer )
{
	_fingers.clear();
	if( buffer->ReadInt() != 'hand' )
	{
		std::cout << "Expected 'hand', got junk." << std::endl;
		return false;
	}

	_id = buffer->ReadInt();
	_palmPosition = buffer->ReadVector();
	_stabilizedPalmPosition = buffer->ReadVector();
	_palmVelocity = buffer->ReadVector();
	_palmNormal = buffer->ReadVector();
	_palmWidth = buffer->ReadFloat();
	_direction = buffer->ReadVector();
	_sphereCenter = buffer->ReadVector();
	_sphereRadius = buffer->ReadFloat();
	_pinchStrength = buffer->ReadFloat();
	_grabStrength = buffer->ReadFloat();
	_confidence = buffer->ReadFloat();

	unsigned int fingers = buffer->ReadInt();
	_fingers.resize( fingers );

	for( unsigned int i = 0; i < fingers; i++ )
	{
		FingerImplementation fi( buffer );
		_fingers[fi.type()] = fi;
	}

	_arm.Unserialize( buffer );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::Translate( const Vector &v )
{
	_palmPosition += v;
	_stabilizedPalmPosition += v;
	_sphereCenter += v;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::Rotate( const Vector &v )
{
	Matrix pitch( Vector::right(), v.x );
	Matrix roll( Vector::backward(), v.y );
	Matrix yaw( Vector::up(), v.z );

	const Matrix *m[] = { &pitch, &roll, &yaw };

	for( int i = 0; i < 3; i++ )
	{
		_palmPosition = m[i]->transformDirection( _palmPosition );
		_stabilizedPalmPosition = m[i]->transformDirection( _stabilizedPalmPosition );
		_palmVelocity = m[i]->transformDirection( _palmVelocity );
		_palmNormal = m[i]->transformDirection( _palmNormal );
		_direction = m[i]->transformDirection( _direction );
		_sphereCenter = m[i]->transformDirection( _sphereCenter );
	}
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
	C_breakpoint();
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
	C_breakpoint();
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
	C_breakpoint();
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
	C_breakpoint();
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
	C_breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::isRight() const
{
	C_breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableList HandImplementation::pointables() const
{
	C_breakpoint();
	return PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable HandImplementation::pointable( int32_t id ) const
{
	C_breakpoint();
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
	C_breakpoint();
	return Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ToolList HandImplementation::tools() const
{
	C_breakpoint();
	return ToolList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Tool HandImplementation::tool( int32_t id ) const
{
	C_breakpoint();
	return Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::translation( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::translationProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::rotationAxis( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationAngle( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationAngle( const Frame &sinceFrame, const Vector& axis ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix HandImplementation::rotationMatrix( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::scaleFactor( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::scaleProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char * HandImplementation::toCString() const
{
	C_breakpoint();
	return "";
}