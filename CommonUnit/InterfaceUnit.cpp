/*
===============================================================================

	Giant Leap

	File	:	InterfaceUnit.cpp
	Authors	:	Lucas Zadrozny
	Date	:	13th September 2014

	Purpose	:	`Interface` unit tests.

===============================================================================
*/

#include "CommonUnit.h"

#include <Windows.h>

#include <iostream>
using namespace std;

#include "GiantLeap.h"
#include "Implementation/ControllerImplementation.h"
#include "Implementation/SharedObject.h"
using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TestImplementation : public Interface::Implementation
{
public:
	TestImplementation()
	{
		_isDeleted = false;
	}

	~TestImplementation()
	{
		_isDeleted = true;
	}

	static bool _isDeleted;
};

bool TestImplementation::_isDeleted = false;

class TestOwned : public Interface
{
public:
	TestOwned( TestImplementation *ref ) : Interface( ref, this )
	{

	}
};

class TestUnowned : public Interface
{
public:
	TestUnowned( TestImplementation *ref ) : Interface( ref, ref )
	{

	}
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_acquired_test );
IMPLEMENT_TEST( perform_unacquired_test );

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool run_interface_test()
{
	RUN_TEST( "Acquiring object", perform_acquired_test );
	RUN_TEST( "Not acquiring object", perform_unacquired_test );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_acquired_test )
{
	TestImplementation *test = new TestImplementation;

	{
		TestOwned owned( test );
		ASSERT( "Checking default state", TestImplementation::_isDeleted == false );
	}

	ASSERT( "Ensuring object is deleted", TestImplementation::_isDeleted == true );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_unacquired_test )
{
	TestImplementation *test = new TestImplementation;

	{
		TestUnowned unowned( test );
		ASSERT( "Checking default state", TestImplementation::_isDeleted == false );
	}

	ASSERT( "Ensuring object is deleted", TestImplementation::_isDeleted == false );
	delete test;

	return true;
}