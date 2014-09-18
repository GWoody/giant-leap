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
#include <map>
using namespace std;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
typedef map<string, FrameImplementation> FrameMap_t;
typedef map<string, bool> AddressMap_t;

//-----------------------------------------------------------------------------
// Prototypes.
//-----------------------------------------------------------------------------
DWORD WINAPI		thread_main( LPVOID lpParam );
bool				received_from_all_addresses( const AddressMap_t &addresses );
void				dispatch_frame( const FrameMap_t &frames );
FrameImplementation	create_final_frame( const FrameMap_t &frames );
void				reset_address_status( AddressMap_t *addresses );

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
// Receives messages from all client applications.
//
// Stores the address of the first received message. This address is used to
// dispatch frames to the host application.
//-----------------------------------------------------------------------------
DWORD WINAPI thread_main( LPVOID lpParam )
{
	void *buf = malloc( 65535 );
	address_t addr;

	FrameMap_t frames;
	AddressMap_t addresses;

	int len = global_socket.Recv( buf, 65535, &addr );
	string masterAddress = addr._address;

	while( !global_quit )
	{
		addresses[addr._address] = true;

		BufferRead rb( buf, len );
		frames[addr._address] = FrameImplementation( &rb );

		if( received_from_all_addresses( addresses ) )
		{
			dispatch_frame( frames );
			frames.clear();
			
			reset_address_status( &addresses );
		}

		len = global_socket.Recv( buf, 65535, &addr );
	}

	free( buf );
	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool received_from_all_addresses( const AddressMap_t &addresses )
{
	for( AddressMap_t::const_iterator it = addresses.begin(); it != addresses.end(); it++ )
	{
		if( !it->second )
		{
			return false;
		}
	}

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void dispatch_frame( const FrameMap_t &frames )
{
	FrameImplementation frame = create_final_frame( frames );

	ControllerImplementation *controller = ControllerImplementation::Get();
	if( controller )
	{
		controller->PushFrame( frame );
		controller->DispatchFrame();
	}
	ControllerImplementation::Release();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FrameImplementation	create_final_frame( const FrameMap_t &frames )
{
	FrameImplementation f;

	for( FrameMap_t::const_iterator it = frames.begin(); it != frames.end(); it++ )
	{
		f.Merge( it->second );
	}

	return f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void reset_address_status( AddressMap_t *addresses )
{
	for( AddressMap_t::iterator it = addresses->begin(); it != addresses->end(); it++ )
	{
		it->second = false;
	}
}
