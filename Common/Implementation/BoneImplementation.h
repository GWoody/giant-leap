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
		void				FromLeap( const Leap::Bone &bone );

		// Networking.
		bool				Serialize( BufferWrite *buffer );
		bool				Unserialize( BufferRead *buffer );

		// Manipulations.
		void				Translate( const Vector &v );
		void				Rotate( const Vector &v );

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