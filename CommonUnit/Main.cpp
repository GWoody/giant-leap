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

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
// Test functions.
//-----------------------------------------------------------------------------
bool run_controller_test();
bool run_shared_object_test();
bool run_frame_test();
bool run_listbase_test();
bool run_arm_test();
bool run_bone_test();
bool run_pointable_test();
bool run_gesture_test();
bool run_tapgesture_test();
bool run_interface_test();
bool run_udpsocket_test();

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main( int argc, char **argv )
{
	RUN_TEST( "ControllerImplementation", run_controller_test );
	RUN_TEST( "SharedObject", run_shared_object_test );
	RUN_TEST( "Frame", run_frame_test );
	RUN_TEST( "ListBase", run_listbase_test );
	RUN_TEST( "Gesture", run_gesture_test );
	RUN_TEST( "Tap Gesture", run_tapgesture_test );
	RUN_TEST( "Arm", run_arm_test );
	RUN_TEST( "Bone", run_bone_test );
	RUN_TEST( "Pointable", run_pointable_test );
	RUN_TEST( "Interface", run_interface_test );
	RUN_TEST( "UDP ", run_udpsocket_test );

	system( "pause" );
	return EXIT_SUCCESS;
}