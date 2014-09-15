/*
===============================================================================

	Giant Leap

	File	:	ControllerUnit.cpp
	Authors	:	Lucas Zadrozny
	Date	:	8th September 2014

	Purpose	:	`ControllerImplementation` unit tests.

===============================================================================
*/

#include "Common.h"
#include "CommonUnit.h"

#include <iostream>
using namespace std;

#include "GiantLeap.h"
#include "Implementation/SharedObject.h"
#include "Implementation/ControllerImplementation.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class CheckImplementation : public Interface::Implementation
{
public:
	CheckImplementation()
	{
		_isDeleted = false;
	}

	~CheckImplementation()
	{
		_isDeleted = true;
	}

	static bool _isDeleted;
};

class Check : public Interface
{
public:
	Check( CheckImplementation *ref ) : Interface( ref, ref )
	{

	}
};

bool CheckImplementation::_isDeleted = false;

//-----------------------------------------------------------------------------
// Tests.
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_simple_self_delete_test );
IMPLEMENT_TEST( perform_complex_self_delete_test );
IMPLEMENT_TEST( perform_implementation_delete_test );

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool run_shared_object_test()
{
	TEST( "simple self delete", perform_simple_self_delete_test );
	TEST( "complex self delete", perform_complex_self_delete_test );
	TEST( "implementation self delete", perform_implementation_delete_test );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_simple_self_delete_test )
{
	CheckImplementation *check = new CheckImplementation;

	SharedObject *shared = SharedObject::Create( check );
	ASSERT( "Checking default state", CheckImplementation::_isDeleted == false );

	shared->DecrementRefCount();
	ASSERT( "Ensuring object is deleted", CheckImplementation::_isDeleted == true );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_complex_self_delete_test )
{
	CheckImplementation *check = new CheckImplementation;

	SharedObject *shared = SharedObject::Create( check );
	ASSERT( "Checking default state", CheckImplementation::_isDeleted == false );

	shared->IncrementRefCount();
	ASSERT( "Ensuring object has not been deleted", CheckImplementation::_isDeleted == false );

	shared->IncrementRefCount();
	ASSERT( "Ensuring object has not been deleted", CheckImplementation::_isDeleted == false );

	shared->DecrementRefCount();
	ASSERT( "Ensuring object has not been deleted", CheckImplementation::_isDeleted == false );

	shared->IncrementRefCount();
	ASSERT( "Ensuring object has not been deleted", CheckImplementation::_isDeleted == false );

	shared->DecrementRefCount();
	ASSERT( "Ensuring object has not been deleted", CheckImplementation::_isDeleted == false );

	shared->DecrementRefCount();
	ASSERT( "Ensuring object has not been deleted", CheckImplementation::_isDeleted == false );

	shared->DecrementRefCount();
	ASSERT( "Ensuring object has been deleted", CheckImplementation::_isDeleted == true );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_implementation_delete_test )
{
	CheckImplementation *imp = new CheckImplementation;

	Check *check = new Check( imp );
	ASSERT( "Ensuring object has not been deleted", CheckImplementation::_isDeleted == false );

	delete check;
	check = NULL;
	ASSERT( "Ensuring object has not been deleted", CheckImplementation::_isDeleted == false );

	delete imp;

	return true;
}