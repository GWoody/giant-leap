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

namespace Leap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Finger` class.
	//-------------------------------------------------------------------------
	class FingerImplementation : public PointableImplementation
	{
	public:
		FingerImplementation();

		Bone				bone( Bone::Type idx ) const;
		Finger::Type		type() const;

		const char *		toCString() const;
	};

}

#endif // __FINGERIMPLEMENTATION_H__