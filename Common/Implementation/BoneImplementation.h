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

#include <list>

namespace Leap
{
	class BoneImplementation : public Interface::Implementation
	{
	public:
		BoneImplementation();
		Vector prevJoint();
		Vector nextJoint();
		Vector center();
		Vector direction();
		float length();
		float width();
		Bone::Type type();
		Matrix basis();
		bool isValid();
		static const Bone& invalid();
		bool operator==(const Bone&);
		bool operator!=(const Bone&); 
		const char* toCString();

	};

}



#endif 