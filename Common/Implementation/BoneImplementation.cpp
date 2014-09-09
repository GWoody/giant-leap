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

Vector Bone::prevJoint() const
{
	return Vector(0, 0, 0);
}

Vector Bone::nextJoint() const
{
	return Vector(0, 0, 0);
}

Vector Bone::center() const
{
	return Vector(0, 0, 0);
}

Vector Bone::direction() const
{
	return Vector(0, 0, 0);
}

float Bone::length() const
{
	return 0;
}

float Bone::width() const
{
	return 0;
}

Bone::Type Bone::type() const
{
	Type type = TYPE_METACARPAL;
	return type;
}

Matrix Bone::basis() const
{
	breakpoint();
	return Matrix();
}

bool Bone::isValid() const
{
	return true;
}

static const Bone& invalid()
{
	Bone bone;

	return bone;
}

bool Bone::operator==(const Bone& b) const
{
	return get<BoneImplementation>() == b.get<BoneImplementation>();
}

bool Bone::operator!=(const Bone& b) const
{
	return get<BoneImplementation>() != b.get<BoneImplementation>();
}

const char* Bone::toCString() const
{
	breakpoint();
	return "";
}