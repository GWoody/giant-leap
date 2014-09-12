/*
===============================================================================

	Giant Leap

	File	:	ArmImplementation.h
	Authors	:	Gareth Woodorth
	Date	:   9th September 2014

	Purpose	:	Implements the Giant Leap version of the `Arm` Leap SDK class.

===============================================================================
*/

#ifndef __ARMIMPLEMENTATION_H__
#define __ARMIMPLEMENTATION_H__

namespace GiantLeap
{
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	class ArmImplementation : public Interface::Implementation
	{
	public:
		ArmImplementation();
		float width() const;
		Leap::Vector direction() const;
		Leap::Matrix basis() const;
		Leap::Vector elbowPosition() const;
		Leap::Vector wristPosition() const;
		bool isValid() const;
		const Arm& invalid();
		bool operator==(const Arm&) const;
		bool operator!=(const Arm&) const;
		const char* toCString() const;
	};

}

#endif // __ARMIMPLEMENTATION_H__