/*
===============================================================================

	Giant Leap

	File	:	Buffer.cpp
	Authors	:	Lucas Zadrozny
	Date	:	11th September 2014

	Purpose	:	Implements the `Buffer` class.

===============================================================================
*/

#include "Common.h"
#include "Buffer.h"

#include "GiantLeap.h"
using namespace GiantLeap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool BufferWrite::WriteShort( short s )
{
	return Write( &s, sizeof(s) );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool BufferWrite::WriteInt( int i )
{
	return Write( &i, sizeof(i) );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool BufferWrite::WriteLongLong( long long l )
{
	return Write( &l, sizeof(l) );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool BufferWrite::WriteFloat( float f )
{
	return Write( &f, sizeof(f) );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool BufferWrite::WriteVector( const GiantLeap::Vector &v )
{
	return WriteFloat( v.x ) && WriteFloat( v.y ) && WriteFloat( v.z );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool BufferWrite::Write( void *memory, int length )
{
	_buffer.reserve( _buffer.size() + length );

	unsigned char *cmem = (unsigned char *)memory;
	for( int i = 0; i < length; ++i )
	{
		_buffer.push_back( cmem[i] );
	}

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const void *BufferWrite::Get() const
{
	return _buffer.data();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int BufferWrite::GetLength() const
{
	return _buffer.size();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
BufferRead::BufferRead( const void *buffer, int length )
{
	_buffer = buffer;
	_length = length;
	_offset = 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
char BufferRead::ReadByte()
{
	char *c = ((char *)_buffer) + _offset;
	_offset++;

	return *c;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
short BufferRead::ReadShort()
{
	char *c = ((char *)_buffer) + _offset;
	short *s = (short *)c;

	_offset += 2;

	return *s;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int BufferRead::ReadInt()
{
	char *c = ((char *)_buffer) + _offset;
	int *i = (int *)c;

	_offset += 4;

	return *i;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
long long BufferRead::ReadLongLong()
{
	char *c = ((char *)_buffer) + _offset;
	long long *l = (long long *)c;

	_offset += 8;

	return *l;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float BufferRead::ReadFloat()
{
	char *c = ((char *)_buffer) + _offset;
	float *f = (float *)c;

	_offset += 4;

	return *f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector BufferRead::ReadVector()
{
	Vector v;

	v.x = ReadFloat();
	v.y = ReadFloat();
	v.z = ReadFloat();

	return v;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void BufferRead::Read( void *buffer, int length )
{
	char *c = ((char *)_buffer) + _offset;

	memcpy( buffer, c, length );
	_offset += length;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const void *BufferRead::Get() const
{
	return _buffer;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int BufferRead::GetLength() const
{
	return _length;
}