/*
===============================================================================

	Giant Leap

	File	:	Network.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Global network definitions.

===============================================================================
*/

#include "Common.h"
#include "Network.h"

#include <WinSock2.h>

bool global_net_initialized = false;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool network_init()
{
	WSADATA wsaData;
	int error = WSAStartup( MAKEWORD(2, 2), &wsaData );

	if( !error )
	{
		global_net_initialized = true;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void network_shutdown()
{
	WSACleanup();
}