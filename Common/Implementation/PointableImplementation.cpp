/*
===============================================================================

	Giant Leap

	File	:	PointableImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `Pointable` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "PointableImplementation.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableImplementation::PointableImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableImplementation::PointableImplementation( const Leap::Pointable &pointable )
{
	FromLeap( pointable );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableImplementation::PointableImplementation( BufferRead *buffer )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void PointableImplementation::FromLeap( const Leap::Pointable &pointable )
{
	_id = pointable.id();
	_tipPosition = pointable.tipPosition();
	_stabilizedTipPosition = pointable.stabilizedTipPosition();
	_tipVelocity = pointable.tipVelocity();
	_direction = pointable.direction();
	_width = pointable.width();
	_length = pointable.length();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool PointableImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'ptbl' );

	buffer->WriteInt( _id );
	buffer->WriteVector( _tipPosition );
	buffer->WriteVector( _stabilizedTipPosition );
	buffer->WriteVector( _tipVelocity );
	buffer->WriteVector( _direction );
	buffer->WriteFloat( _width );
	buffer->WriteFloat( _length );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool PointableImplementation::Unserialize( BufferRead *buffer )
{
	if( buffer->ReadInt() != 'ptbl' )
	{
		std::cout << "Expected 'ptbl', got junk." << std::endl;
		return false;
	}

	_id = buffer->ReadInt();
	_tipPosition = buffer->ReadVector();
	_stabilizedTipPosition = buffer->ReadVector();
	_tipVelocity = buffer->ReadVector();
	_direction = buffer->ReadVector();
	_width = buffer->ReadFloat();
	_length = buffer->ReadFloat();

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void PointableImplementation::Translate( const Vector &v )
{
	_tipPosition += v;
	_stabilizedTipPosition += v;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void PointableImplementation::Rotate( const Matrix &pry )
{
	_tipPosition = pry.transformDirection( _tipPosition );
	_stabilizedTipPosition = pry.transformDirection( _stabilizedTipPosition );
	_tipVelocity = pry.transformDirection( _tipVelocity );
	_direction = pry.transformDirection( _direction );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int32_t PointableImplementation::id() const
{
	return _id;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Frame PointableImplementation::frame() const
{
	C_breakpoint();
	return Frame();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Hand PointableImplementation::hand() const
{
	C_breakpoint();
	return Hand::invalid();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector PointableImplementation::tipPosition() const
{
	return _tipPosition;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector PointableImplementation::stabilizedTipPosition() const
{
	return _stabilizedTipPosition;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector PointableImplementation::tipVelocity() const
{
	return _tipVelocity;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector PointableImplementation::direction() const
{
	return _direction;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float PointableImplementation::width() const
{
	return _width;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float PointableImplementation::length() const
{
	return _length;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float PointableImplementation::timeVisible() const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool PointableImplementation::isFinger() const
{
	C_breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool PointableImplementation::isTool() const
{
	C_breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool PointableImplementation::isExtended() const
{
	C_breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable::Zone PointableImplementation::touchZone() const
{
	C_breakpoint();
	return Pointable::Zone();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float PointableImplementation::touchDistance() const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char *PointableImplementation::toCString() const
{
	C_breakpoint();
	return "";
}