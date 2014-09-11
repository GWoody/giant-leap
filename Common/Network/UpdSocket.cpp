/*
===============================================================================

	Giant Leap

	File	:	UpdSocket.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Socket abstraction layer.

===============================================================================
*/

#include "Common.h"
#include "Network.h"
#include "Socket.h"

#include <WinSock2.h>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UdpSocket::UdpSocket( bool recv, unsigned short port )
{
	_recv = recv;
	_port = port;

	if( !global_net_initialized )
	{
		network_init();
	}

	_fd = socket( AF_INET, SOCK_DGRAM, 0 );

	if( recv )
	{
		sockaddr_in addr;
		memset( &addr, 0, sizeof(addr) );
		addr.sin_family = AF_INET;
		addr.sin_addr.S_un.S_addr = htonl( INADDR_ANY );
		addr.sin_port = htons( port );

		bind( _fd, (sockaddr *)&addr, sizeof(addr) );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool UdpSocket::Send( const void *buf, int len, const char *address )
{
	if( !_recv )
	{
		sockaddr_in sendaddr;
		memset( &sendaddr, 0, sizeof(sendaddr) );
		sendaddr.sin_family = AF_INET;
		sendaddr.sin_addr.S_un.S_addr = inet_addr( address );
		sendaddr.sin_port = htons( _port );

		return sendto( _fd, (const char *)buf, len, 0, (sockaddr *)&sendaddr, sizeof(sendaddr) ) != SOCKET_ERROR;
	}

	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool UdpSocket::Recv( void *buf, int buflen, address_t *addr )
{
	if( _recv )
	{
		sockaddr_in from;
		int fromlen = sizeof(from);

		int error =  recvfrom( _fd, (char *)buf, buflen, 0, (sockaddr *)&from, &fromlen );
		if( error != SOCKET_ERROR && addr )
		{
			strncpy_s( addr->_address, inet_ntoa( from.sin_addr ), sizeof(addr->_address) );
			addr->_port = ntohs( from.sin_port );
		}

		return error != SOCKET_ERROR;
	}

	return false;
}