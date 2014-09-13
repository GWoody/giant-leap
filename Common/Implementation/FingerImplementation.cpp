/*
===============================================================================

	Giant Leap

	File	:	FingerImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `Finger` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "FingerImplementation.h"
using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerImplementation::FingerImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerImplementation::FingerImplementation( const Leap::Finger &finger )
{
	FromLeap( finger );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerImplementation::FingerImplementation( BufferRead *buffer )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FingerImplementation::FromLeap( const Leap::Finger &finger )
{
	_type = (GiantLeap::Finger::Type)finger.type();

	_bones.clear();

	for( int i = 0; i < 4; i++ )
	{
		Leap::Bone::Type leapBoneType = (Leap::Bone::Type)i;
		const Leap::Bone &lb = finger.bone( leapBoneType );

		BoneImplementation bi( lb );
		_bones.push_back( bi );
	}

	PointableImplementation::FromLeap( finger );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool FingerImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'fngr' );

	buffer->WriteInt( _type );

	buffer->WriteInt( _bones.size() );
	for( unsigned int i = 0; i < _bones.size(); i++ )
	{
		_bones[i].Serialize( buffer );
	}

	return PointableImplementation::Serialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool FingerImplementation::Unserialize( BufferRead *buffer )
{
	_bones.clear();

	if( buffer->ReadInt() != 'fngr' )
	{
		std::cout << "Expected 'fngr', got junk." << std::endl;
		return false;
	}

	_type = (GiantLeap::Finger::Type)buffer->ReadInt();

	unsigned int bones = buffer->ReadInt();
	_bones.resize( bones );
	for( unsigned int i = 0; i < bones; i++ )
	{
		BoneImplementation bi( buffer );
		_bones[bi.type()] = bi;
	}

	return PointableImplementation::Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FingerImplementation::Translate( const Vector &v )
{
	for( unsigned int i = 0; i < _bones.size(); i++ )
	{
		_bones[i].Translate( v );
	}

	PointableImplementation::Translate( v );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FingerImplementation::Rotate( const Vector &v )
{
	for( unsigned int i = 0; i < _bones.size(); i++ )
	{
		_bones[i].Rotate( v );
	}

	PointableImplementation::Rotate( v );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Bone FingerImplementation::bone( Bone::Type idx ) const
{
	return Bone( (BoneImplementation *)&_bones[idx] );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Finger::Type FingerImplementation::type() const
{
	return _type;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char *FingerImplementation::toCString() const
{
	breakpoint();
	return "";
}