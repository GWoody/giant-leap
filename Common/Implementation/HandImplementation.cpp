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
#include "ListBaseImplementation.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation::HandImplementation() :
	_arm( Arm(), NULL )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation::HandImplementation( const Leap::Hand &hand ) :
	_arm( Arm(), NULL )
{
	FromLeap( hand );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation::HandImplementation( BufferRead *buffer ) :
	_arm( Arm(), NULL )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::FromLeap( const Leap::Hand &hand )
{
	//
	// Read misc.
	//
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

	//
	// Read fingers.
	//
	const Leap::FingerList &fingers = hand.fingers();
	for( int i = 0; i < fingers.count(); i++ )
	{
		FingerImplementation *fi = new FingerImplementation( fingers[i] );
		Finger f( fi );

		_fingers.push_back( FingerPair_t( f, fi ) );
	}

	//
	// Read arm.
	//
	ArmImplementation *ai = new ArmImplementation( hand.arm() );
	Arm a( ai );
	_arm = ArmPair_t( a, ai );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'hand' );

	//
	// Write misc.
	//
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

	//
	// Write fingers.
	//
	buffer->WriteInt( _fingers.size() );
	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		_fingers[i].GetImplementation()->Serialize( buffer );
	}

	//
	// Write arm.
	//
	_arm.GetImplementation()->Serialize( buffer );

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

	//
	// Read misc.
	//
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

	//
	// Read fingers.
	//
	unsigned int fingers = buffer->ReadInt();
	for( unsigned int i = 0; i < fingers; i++ )
	{
		FingerImplementation *fi = new FingerImplementation();
		if( !fi->Unserialize( buffer ) )
		{
			std::cerr << "HandImplementation::Unserialize - failed to read finger" << std::endl;
			delete fi;
			return false;
		}

		Finger f( fi );
		_fingers.push_back( FingerPair_t( f, fi ) );
	}

	//
	// Read arm.
	//
	ArmImplementation *ai = new ArmImplementation();
	if( !ai->Unserialize( buffer ) )
	{
		return false;
	}

	Arm a( ai );
	_arm = ArmPair_t( a, ai );

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
	return _arm.GetInterface();
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
	ListBaseImplementation<Finger> *list = new ListBaseImplementation<Finger>;

	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		list->push_back( _fingers[i].GetInterface() );
	}

	return FingerList( *list );
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