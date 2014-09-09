/*
===============================================================================

Giant Leap

File	:	ArmImplementation.cpp
Authors	:	Gareth Woodorth
Date	:   9th September 2014

Purpose	:	Implements the Giant Leap version of the `ArmImplementation` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "ArmImplementation.h"

using namespace Leap;

ArmImplementation::ArmImplementation()
{
	
}

float ArmImplementation::width()
{
	return 0;
}

Vector Arm::direction() const 
{
	return Vector(0, 0, 0);
}

Matrix Arm::basis() const
{
	breakpoint();
	return Matrix();
}

Vector Arm::elbowPosition() const
{
	return Vector(0,0,0);
}

Vector Arm::wristPosition() const
{
	return Vector(0, 0, 0);
}

bool Arm::isValid() const
{
	return true;
}

const Arm& Arm::invalid()
{
	static Arm invalid(NULL);
	return invalid;
}

bool Arm::operator==(const Arm& other) const
{
	return true;
}

bool Arm::operator!=(const Arm& other) const
{
	return true;
}

const char* Arm::toCString() const
{
	breakpoint();
	return "";
}