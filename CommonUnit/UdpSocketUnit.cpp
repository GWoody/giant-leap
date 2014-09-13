/*
===============================================================================

	Giant Leap

	File	:	UdpSocketUnit.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	`UdpSocket` unit tests.

===============================================================================
*/

#include "CommonUnit.h"

#include <Windows.h>

#include <iostream>
using namespace std;

#include "GiantLeap.h"
#include "Network/Socket.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
// Tests.
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_local_connection_test );

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool run_udpsocket_test()
{
	TEST( "local connection", perform_local_connection_test );
	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST( perform_local_connection_test )
{
	UdpSocket client( false, 27015 );
	UdpSocket server( true, 27015 );

	const char *testString = "hi there this is a test string which will determine if data is being sent from the client socket to the server socket\n";
	char recvBuf[512];
	address_t addr;

	ASSERT( "Ensuring client socket cannot recv", !client.Recv( recvBuf, sizeof(recvBuf), &addr ) );
	ASSERT( "Ensuring server socket cannot send", !server.Send( testString, strlen(testString) + 1, "127.0.0.1" ) );

	client.Send( testString, strlen(testString) + 1, "127.0.0.1" );
	server.Recv( recvBuf, sizeof(recvBuf), &addr );

	ASSERT( "Ensuring server receives valid data", !strncmp( testString, recvBuf, 512 ) );

	return true;
}