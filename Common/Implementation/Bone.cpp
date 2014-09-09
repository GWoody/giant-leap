/*
===============================================================================

Giant Leap

File	:	Bone.cpp
Authors	:	Gareth Woodorth
Date	:   9th September 2014

Purpose	:	Implements the Giant Leap version of the `Bone` Leap SDK class.

===============================================================================
*/

#include "Leap.h"
#include "BoneImplementation.h"
#include "SharedObject.h"

using namespace Leap;

Bone::Bone(BoneImplementation *ref) : Interface(ref, this)
{

}

LEAP_EXPORT Bone::Bone() : Interface((SharedObject *)NULL)
{

}

LEAP_EXPORT Vector Bone::prevJoint() const
{
	return get<BoneImplementation>()->prevJoint();
}

LEAP_EXPORT Vector Bone::nextJoint() const
{
	return get<BoneImplementation>()->nextJoint();
}


LEAP_EXPORT Vector Bone::center() const
{
	return get<BoneImplementation>()->center();
}


LEAP_EXPORT Vector Bone::direction() const
{
	return get<BoneImplementation>()->direction();
}

LEAP_EXPORT float Bone::length() const
{
	return get<BoneImplementation>()->length();
}

LEAP_EXPORT float Bone::width() const
{
	return get<BoneImplementation>()->width();
}

LEAP_EXPORT Bone::Type Bone::type() const
{
	return get<BoneImplementation>()->type();
}

LEAP_EXPORT Matrix Bone::basis() const
{
	return get<BoneImplementation>()->basis();
}

LEAP_EXPORT bool Bone::isValid() const
{
	return get<BoneImplementation>()->isValid();
}

LEAP_EXPORT bool Bone::operator==(const Bone& b) const
{
	return get<BoneImplementation>() == b.get<BoneImplementation>();
}

LEAP_EXPORT bool Bone::operator!=(const Bone& b) const
{
	return get<BoneImplementation>() != b.get<BoneImplementation>();
}

LEAP_EXPORT std::ostream& operator<<(std::ostream& out , const Bone& b)
{
	out << b.toString();
	return out;
}

LEAP_EXPORT const char* Bone::toCString() const
{
	return get<BoneImplementation>()->toCString();
}

