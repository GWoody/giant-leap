/*
===============================================================================

Giant Leap

File	:	BoneImplementation.cpp
Authors	:	Gareth Woodorth
Date	:   9th September 2014

Purpose	:	Implements the Giant Leap version of the `BoneImplementation` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "BoneImplementation.h"

using namespace Leap;

BoneImplementation::BoneImplementation()
{

}

Vector BoneImplementation::prevJoint() const
{
	return Vector(0, 0, 0);
}

Vector BoneImplementation::nextJoint() const
{
	return Vector(0, 0, 0);
}

Vector BoneImplementation::center() const
{
	return Vector(0, 0, 0);
}

Vector BoneImplementation::direction() const
{
	return Vector(0, 0, 0);
}

float BoneImplementation::length() const
{
	return 0;
}

float BoneImplementation::width() const
{
	return 0;
}

Bone::Type Bone::type() const
{
	Type type = TYPE_METACARPAL;
	return type;
}

Matrix BoneImplementation::basis() const
{
	breakpoint();
	return Matrix();
}

bool BoneImplementation::isValid() const
{
	return true;
}

 const Bone& BoneImplementation::invalid()
{
	 static Bone invalid(NULL);
	 return invalid;
}

bool BoneImplementation::operator==(const Bone& b) const
{
	return true;
}

bool BoneImplementation::operator!=(const Bone& b) const
{
	return true;
}

const char* BoneImplementation::toCString() const
{
	breakpoint();
	return "";
}