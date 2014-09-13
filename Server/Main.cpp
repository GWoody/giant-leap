/*
===============================================================================

	Giant Leap

	File	:	Main.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	High level Giant Leap functionality.

===============================================================================
*/

#include "GiantLeap.h"
#include "Common.h"
#include "Network/Socket.h"
#include "Network/Buffer.h"
#include "Implementation/FrameImplementation.h"
#include "Implementation/ControllerImplementation.h"
using namespace GiantLeap;

#include <Windows.h>
#include <Subauth.h>

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
// Prototypes.
//-----------------------------------------------------------------------------
DWORD WINAPI thread_main( LPVOID lpParam );

//-----------------------------------------------------------------------------
// Global variables.
//-----------------------------------------------------------------------------
UdpSocket global_socket( true, GIANT_LEAP_PORT );
HANDLE global_thread_handle = NULL;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GiantLeap::Init::Init()
{
	global_thread_handle = CreateThread( NULL, 0, thread_main, NULL, 0, NULL );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GiantLeap::Init::~Init()
{
	// TODO: kill thread.

	_CrtDumpMemoryLeaks();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
DWORD WINAPI thread_main( LPVOID lpParam )
{
	void *buf = malloc( 65535 );
	address_t addr;

	while( true )
	{
		int len = global_socket.Recv( buf, 65535, &addr );

		BufferRead rb( buf, len );
		FrameImplementation frame( &rb );

		ControllerImplementation *controller = ControllerImplementation::Get();
		controller->PushFrame( frame );
		controller->DispatchFrame();
	}

	return 0;
}