/*
===============================================================================

Giant Leap

File	:	Arm.cpp
Authors	:	Gareth Woodorth
Date	:   9th September 2014

Purpose	:	Implements the Giant Leap version of the `Arm` Leap SDK class.

===============================================================================
*/


#include "Leap.h"
#include "ArmImplementation.h"
#include "SharedObject.h"

using namespace Leap;

Arm::Arm(ArmImplementation *ref) : Interface(ref, this)
{

}

LEAP_EXPORT Arm::Arm(): Interface((SharedObject *)NULL)
{
	
}


LEAP_EXPORT float Arm::width() const
{
	return get<ArmImplementation>()->width();
}

LEAP_EXPORT Vector Arm::direction() const
{
	return get<ArmImplementation>()->direction();
}

LEAP_EXPORT Matrix Arm::basis() const
{
	return get<ArmImplementation>()->basis();
}


LEAP_EXPORT Vector Arm::elbowPosition() const
{
	return get<ArmImplementation>()->elbowPosition();
}

LEAP_EXPORT Vector Arm::wristPosition() const
{
	return get<ArmImplementation>()->wristPosition();
}

LEAP_EXPORT bool Arm::isValid() const
{
	return get<ArmImplementation>()->isValid();
}

LEAP_EXPORT const Arm& Arm::invalid()
{
	static Arm invalid(NULL);
	return invalid;
}

LEAP_EXPORT bool Arm::operator==(const Arm& other) const
{
	return get<ArmImplementation>() == other.get<ArmImplementation>();
}

LEAP_EXPORT bool Arm::operator!=(const Arm& other) const
{
	return get<ArmImplementation>() != other.get<ArmImplementation>();
}

LEAP_EXPORT  std::ostream& operator<<(std::ostream& out, const Arm& a)
{
	out << a.toString();
	return out;
}

LEAP_EXPORT const char* Arm::toCString() const
{
	//return get<ArmImplementation>()->toCString();
}

