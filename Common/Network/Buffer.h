/*
===============================================================================

	Giant Leap

	File	:	Buffer.h
	Authors	:	Lucas Zadrozny
	Date	:	11th September 2014

	Purpose	:	Defines the `Buffer` class.

===============================================================================
*/

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <vector>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class BufferWrite
{
public:
	// Writing.
	bool				Write( void *buffer, int length );

	// Accessors.
	const void *		Get() const;
	int					GetLength() const;

private:
	std::vector<unsigned char>	_buffer;
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class BufferRead
{
public:
	BufferRead( const void *buffer, int length );
	
	char				ReadByte();
	short				ReadShort();
	int					ReadInt();
	long long			ReadLongLong();
	float				ReadFloat();
	Leap::Vector		ReadVector();
	void				Read( void *buffer, int length );

	// Accessors.
	const void *		Get() const;
	int					GetLength() const;

private:
	const void *		_buffer;
	int					_length;
	int					_offset;
};

#endif // __BUFFER_H__