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
			float width() const;
			Vector direction() const;
			Matrix basis() const;
			Vector elbowPosition() const;
			Vector wristPosition() const;
			bool isValid() const;
			const Arm& invalid();
			bool operator==(const Arm&) const;
			bool operator!=(const Arm&) const;
			const char* toCString() const;

	};

}



#endif 