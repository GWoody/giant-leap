/*
===============================================================================

	Giant Leap

	File	:	BoneImplementation.cpp
	Authors	:	Gareth Woodorth
	Date	:   9th September 2014

	Purpose	:	Implements the Giant Leap version of the `BoneImplementation` Leap SDK class.

===============================================================================
*/

#ifndef __BONEIMPLEMENTATION_H__
#define __BONEIMPLEMENTATION_H__

namespace GiantLeap
{
	
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	class BoneImplementation : public Interface::Implementation
	{
	public:
		BoneImplementation();
		Leap::Vector prevJoint() const;
		Leap::Vector nextJoint() const;
		Leap::Vector center() const;
		Leap::Vector direction() const;
		float length() const;
		float width() const;
		Bone::Type type() const;
		Leap::Matrix basis() const;
		bool isValid() const;
		static const Bone& invalid();
		bool operator==(const Bone&) const;
		bool operator!=(const Bone&) const; 
		const char* toCString() const;
	};

}

#endif // __BONEIMPLEMENTATION_H__