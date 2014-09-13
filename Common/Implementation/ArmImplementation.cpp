/*
===============================================================================

	Giant Leap

	File	:	ArmImplementation.cpp
	Authors	:	Gareth Woodorth
	Date	:   9th September 2014

	Purpose	:	Implements the Giant Leap version of the `Arm` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "ArmImplementation.h"

using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ArmImplementation::ArmImplementation()
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ArmImplementation::ArmImplementation( const Leap::Arm &arm )
{
	FromLeap( arm );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ArmImplementation::ArmImplementation( BufferRead *buffer )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ArmImplementation::FromLeap( const Leap::Arm &arm )
{
	_width = arm.width();
	_elbowPosition = arm.elbowPosition();
	_wristPosition = arm.wristPosition();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ArmImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'army' );

	buffer->WriteFloat( _width );
	buffer->WriteVector( _elbowPosition );
	buffer->WriteVector( _wristPosition );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ArmImplementation::Unserialize( BufferRead *buffer )
{
	if( buffer->ReadInt() != 'army' )
	{
		std::cout << "Expected 'army', got junk." << std::endl;
		return false;
	}

	_width = buffer->ReadFloat();
	_elbowPosition = buffer->ReadVector();
	_wristPosition = buffer->ReadVector();

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ArmImplementation::Translate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ArmImplementation::Rotate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float ArmImplementation::width() const
{
	return _width;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector ArmImplementation::direction() const
{
	return ( _wristPosition - _elbowPosition ).normalized();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix ArmImplementation::basis() const
{
	C_breakpoint();
	return Matrix();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector ArmImplementation::elbowPosition() const
{
	return _elbowPosition;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector ArmImplementation::wristPosition() const
{
	return _wristPosition;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char* ArmImplementation::toCString() const
{
	C_breakpoint();
	return "";
}