/*
===============================================================================

	Giant Leap

	File	:	Main.cpp
	Authors	:	Lucas Zadrozny
	Date	:	6th September 2014

	Purpose	:	Mainline for the Giant Leap common library unit test application.

===============================================================================
*/

#include "CommonUnit.h"

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
// Test functions.
//-----------------------------------------------------------------------------
bool run_controller_test();

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main( int argc, char **argv )
{
	RUN_TEST( "ControllerImplementation", run_controller_test );

	system( "pause" );
	return EXIT_SUCCESS;
}