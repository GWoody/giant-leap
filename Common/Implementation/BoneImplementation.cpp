/*
===============================================================================

	Giant Leap

	File	:	BoneImplementation.cpp
	Authors	:	Gareth Woodorth
	Date	:   9th September 2014

	Purpose	:	Implements the Giant Leap version of the `BoneImplementation` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "BoneImplementation.h"

using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BoneImplementation::BoneImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BoneImplementation::BoneImplementation( const Leap::Bone &bone )
{
	FromLeap( bone );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BoneImplementation::BoneImplementation( BufferRead *buffer )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void BoneImplementation::FromLeap( const Leap::Bone &bone )
{
	_type = (Bone::Type)bone.type();
	_nextJoint = bone.nextJoint();
	_prevJoint = bone.prevJoint();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool BoneImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'bone' );

	buffer->WriteInt( _type );
	buffer->WriteVector( _nextJoint );
	buffer->WriteVector( _prevJoint );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool BoneImplementation::Unserialize( BufferRead *buffer )
{
	if( buffer->ReadInt() != 'bone' )
	{
		return false;
	}

	_type = (Bone::Type)buffer->ReadInt();
	_nextJoint = buffer->ReadVector();
	_prevJoint = buffer->ReadVector();

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void BoneImplementation::Translate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void BoneImplementation::Rotate( const Vector &v )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector BoneImplementation::prevJoint() const
{
	return _prevJoint;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector BoneImplementation::nextJoint() const
{
	return _nextJoint;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector BoneImplementation::center() const
{
	breakpoint();
	return Vector(0, 0, 0);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector BoneImplementation::direction() const
{
	return ( _nextJoint - _prevJoint ).normalized();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float BoneImplementation::length() const
{
	breakpoint();
	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float BoneImplementation::width() const
{
	breakpoint();
	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Bone::Type BoneImplementation::type() const
{
	return _type;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix BoneImplementation::basis() const
{
	breakpoint();
	return Matrix();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char* BoneImplementation::toCString() const
{
	breakpoint();
	return "";
}