/*
===============================================================================

	Giant Leap

	File	:	FingerImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the real logic behind the `Finger` class.

===============================================================================
*/

#ifndef __FINGERIMPLEMENTATION_H__
#define __FINGERIMPLEMENTATION_H__

#include "PointableImplementation.h"
#include "BoneImplementation.h"
#include "Network/Buffer.h"

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Finger` class.
	//-------------------------------------------------------------------------
	class FingerImplementation : public PointableImplementation
	{
	public:
		FingerImplementation();
		FingerImplementation( const Leap::Finger &finger );
		FingerImplementation( BufferRead *buffer );

		// Initialization.
		void				FromLeap( const Leap::Finger &finger );

		// Networking.
		bool				Serialize( BufferWrite *buffer );
		bool				Unserialize( BufferRead *buffer );

		// Manipulations.
		void				Translate( const Vector &v );
		void				Rotate( const Vector &v );

		// Leap interface.
		Bone				bone( Bone::Type idx ) const;
		Finger::Type		type() const;

		const char *		toCString() const;

	private:
		Finger::Type		_type;
		std::vector<BoneImplementation>	_bones;
	};

}

#endif // __FINGERIMPLEMENTATION_H__