/*
===============================================================================

	Giant Leap

	File	:	Common.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Shared common module definitions.

===============================================================================
*/

#include "Common.h"
using namespace GiantLeap;

#include <sstream>
using namespace std;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector string_to_vector( const std::string &str )
{
	istringstream sin( str );
	Vector v;

	sin >> v.x >> v.y >> v.z;
	return v;
}