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

#include "MemDebugOn.h"

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

		BoneImplementation *bi = new BoneImplementation( lb );
		Bone b( bi );
		_bones.push_back( BonePair_t( b, bi ) );
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
		_bones[i].GetImplementation()->Serialize( buffer );
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
	for( unsigned int i = 0; i < bones; i++ )
	{
		BoneImplementation *bi = new BoneImplementation();
		if( !bi->Unserialize( buffer ) )
		{
			std::cerr << "FingerImplementation::Unserialize - failed to read bone" << std::endl;
			delete bi;
			return false;
		}

		Bone b( bi );
		_bones.push_back( BonePair_t( b, bi ) );
	}

	return PointableImplementation::Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FingerImplementation::Translate( const Vector &v )
{
	for( unsigned int i = 0; i < _bones.size(); i++ )
	{
		_bones[i].GetImplementation()->Translate( v );
	}

	PointableImplementation::Translate( v );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void FingerImplementation::Rotate( const Matrix &pry )
{
	for( unsigned int i = 0; i < _bones.size(); i++ )
	{
		_bones[i].GetImplementation()->Rotate( pry );
	}

	PointableImplementation::Rotate( pry );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Bone FingerImplementation::bone( Bone::Type idx ) const
{
	idx = (Bone::Type)C_clamp( idx, 0, (int)_bones.size() );
	return _bones[idx].GetInterface();
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
	C_breakpoint();
	return "";
}