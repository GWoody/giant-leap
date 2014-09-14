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
#include "Network/Network.h"
#include "Implementation/FrameImplementation.h"
#include "Implementation/ControllerImplementation.h"
using namespace GiantLeap;

#include <Windows.h>
#include <Subauth.h>

#include <iostream>
using namespace std;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
// Prototypes.
//-----------------------------------------------------------------------------
DWORD WINAPI thread_main( LPVOID lpParam );

//-----------------------------------------------------------------------------
// Global variables.
//-----------------------------------------------------------------------------
UdpSocket global_socket( true, GIANT_LEAP_PORT );
HANDLE global_thread_handle = NULL;

bool global_quit = false;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GiantLeap::Init::Init()
{
	global_thread_handle = CreateThread( NULL, 0, thread_main, NULL, 0, NULL );
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GiantLeap::Init::~Init()
{
	global_quit = true;
	WaitForSingleObject( global_thread_handle, INFINITE );
	CloseHandle( global_thread_handle );

	if( global_net_initialized )
	{
		network_shutdown();
	}
}	

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
DWORD WINAPI thread_main( LPVOID lpParam )
{
	void *buf = malloc( 65535 );
	address_t addr;

	while( !global_quit )
	{
		int len = global_socket.Recv( buf, 65535, &addr );

		BufferRead rb( buf, len );
		FrameImplementation frame( &rb );

		ControllerImplementation *controller = ControllerImplementation::Get();
		if( controller )
		{
			controller->PushFrame( frame );
			controller->DispatchFrame();
		}
		ControllerImplementation::Release();
	}

	free( buf );
	return 0;
}