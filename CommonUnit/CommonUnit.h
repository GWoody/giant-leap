/*
===============================================================================

	Giant Leap

	File	:	CommonUnit.h
	Authors	:	Lucas Zadrozny
	Date	:	6th September 2014

	Purpose	:	Shared definitions for the `CommonUnit` application.

===============================================================================
*/

#ifndef __COMMONUNIT_H__
#define __COMMONUNIT_H__

//-----------------------------------------------------------------------------
// Attaches the debugger.
//-----------------------------------------------------------------------------
#define BREAKPOINT()		__asm { int 3 }

//-----------------------------------------------------------------------------
// Tests a function that returns a boolean.
//-----------------------------------------------------------------------------
#define RUN_TEST( name, func )	cout << "Testing " << name << endl;	\
	if( !func() ) {								\
		cout << #func << " failed!" << endl;	\
		BREAKPOINT();							\
		system( "pause" );						\
		exit( EXIT_FAILURE );					\
}

//-----------------------------------------------------------------------------
// Implements a function that tests an object.
//-----------------------------------------------------------------------------
#define IMPLEMENT_TEST_OBJECT( func, type, obj )	bool func( type *obj )

//-----------------------------------------------------------------------------
// Calls a function that tests an object.
//-----------------------------------------------------------------------------
#define TEST_OBJECT( name, func, obj )	cout << "\tTesting " << name << endl;	\
	if( !func( obj ) ) {						\
		cout << #func << " failed!" << endl;	\
		BREAKPOINT();							\
		system( "pause" );						\
		exit( EXIT_FAILURE );					\
}

//-----------------------------------------------------------------------------
// Ensures a test condition passes.
//-----------------------------------------------------------------------------
#define ASSERT( str, expr )		cout << "\t\t" << str << "...";	\
	if( expr )	{								\
		cout << "Passed!" << endl;				\
	} else {									\
		cout << "Failed!" << endl;				\
		BREAKPOINT();							\
		system( "pause" );						\
		exit( EXIT_FAILURE );					\
	}


#endif // __COMMONUNIT_H__