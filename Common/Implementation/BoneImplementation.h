/*
===============================================================================

	Giant Leap

	File	:	BoneImplementation.cpp
	Authors	:	Gareth Woodorth
	Date	:   9th September 2014

	Purpose	:	Implements the Giant Leap version of the `BoneImplementation` Leap SDK class.

===============================================================================
*/

#ifndef __BONEIMPLEMENTATION_H__
#define __BONEIMPLEMENTATION_H__

#include "Network/Buffer.h"
#include "Pair.h"

namespace GiantLeap
{
	
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	class BoneImplementation : public Interface::Implementation
	{
	public:
		BoneImplementation();
		BoneImplementation( const Leap::Bone &bone );
		BoneImplementation( BufferRead *buffer );

		// Initialization.
		virtual void		FromLeap( const Leap::Bone &bone );

		// Networking.
		virtual bool		Serialize( BufferWrite *buffer );
		virtual bool		Unserialize( BufferRead *buffer );

		// Manipulations.
		virtual void		Translate( const Vector &v );
		virtual void		Rotate( const Matrix &pry );

		BoneImplementation	operator+( const BoneImplementation &rhs ) const;
		BoneImplementation	operator*( float scale ) const;
		BoneImplementation	operator/( float scale ) const;

		// Leap interface.
		Vector				prevJoint() const;
		Vector				nextJoint() const;
		Vector				center() const;
		Vector				direction() const;
		float				length() const;
		float				width() const;
		Bone::Type			type() const;
		Matrix				basis() const;
		const char*			toCString() const;

	private:
		Bone::Type			_type;
		Vector				_nextJoint;
		Vector				_prevJoint;
	};

}

#endif // __BONEIMPLEMENTATION_H__