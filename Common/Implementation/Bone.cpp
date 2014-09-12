/*
===============================================================================

	Giant Leap

	File	:	Bone.cpp
	Authors	:	Gareth Woodorth
	Date	:   9th September 2014

	Purpose	:	Implements the Giant Leap version of the `Bone` Leap SDK class.

===============================================================================
*/

#include "GiantLeap.h"
#include "BoneImplementation.h"
#include "SharedObject.h"

using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Bone::Bone(BoneImplementation *ref) : Interface(ref, this)
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Bone::Bone() : Interface((SharedObject *)NULL)
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Bone::prevJoint() const
{
	return isValid() ? get<BoneImplementation>()->prevJoint() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Bone::nextJoint() const
{
	return isValid() ? get<BoneImplementation>()->nextJoint() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Bone::center() const
{
	return isValid() ? get<BoneImplementation>()->center() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Vector Bone::direction() const
{
	return isValid() ? get<BoneImplementation>()->direction() : Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Bone::length() const
{
	return isValid() ? get<BoneImplementation>()->length() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT float Bone::width() const
{
	return isValid() ? get<BoneImplementation>()->width() : 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Bone::Type Bone::type() const
{
	return isValid() ? get<BoneImplementation>()->type() : Bone::TYPE_METACARPAL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Matrix Bone::basis() const
{
	return isValid() ? get<BoneImplementation>()->basis() : Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Bone::isValid() const
{
	return get<BoneImplementation>() != NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Bone::operator==(const Bone& b) const
{
	return get<BoneImplementation>() == b.get<BoneImplementation>();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool Bone::operator!=(const Bone& b) const
{
	return get<BoneImplementation>() != b.get<BoneImplementation>();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT std::ostream& operator<<(std::ostream& out , const Bone& b)
{
	out << b.toString();
	return out;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT const char* Bone::toCString() const
{
	return isValid() ? get<BoneImplementation>()->toCString() : "";
}

