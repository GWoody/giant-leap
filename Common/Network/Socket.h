/*
===============================================================================

	Giant Leap

	File	:	Socket.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Socket abstraction layer.

===============================================================================
*/

#ifndef __UDPSOCKET_H__
#define __UDPSOCKET_H__

#define GIANT_LEAP_PORT		16807

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct address_t
{
	char				_address[16];
	unsigned short		_port;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class StreamSocket
{
public:

};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class UdpSocket
{
public:
	LEAP_EXPORT UdpSocket( bool recv, unsigned short port );

	LEAP_EXPORT virtual bool		Send( const void *buf, int len, const char *address );
	LEAP_EXPORT virtual int			Recv( void *buf, int buflen, address_t *addr );

protected:
	int					_fd;
	bool				_recv;
	unsigned short		_port;
};

#endif // __UDPSOCKET_H__