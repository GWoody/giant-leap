/*
===============================================================================

Giant Leap

File	:	ArmImplementation.h
Authors	:	Gareth Woodorth
Date	:   9th September 2014

Purpose	:	Implements the Giant Leap version of the `ArmImplementation` Leap SDK class.

===============================================================================
*/

#ifndef __ARMIMPLEMENTATION_H__
#define __ARMIMPLEMENTATION_H__

#include <list>

namespace Leap
{
	class ArmImplementation : public Interface::Implementation
	{
		public:
			ArmImplementation();
			float width();
			Vector direction();
			Matrix basis();
			Vector elbowPosition();
			Vector wristPosition();
			bool isValid();
			const Arm& invalid();
			bool operator==(const Arm&);
			bool operator!=(const Arm&);
			const char* toCString();

	};

}



#endif 