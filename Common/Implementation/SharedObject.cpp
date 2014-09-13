/*
===============================================================================

	Giant Leap

	File	:	SharedObject.cpp
	Authors	:	Lucas Zadrozny
	Date	:	13th September 2014

	Purpose	:	Implements the `SharedPointer` object.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "SharedObject.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SharedObject *SharedObject::Create( Interface::Implementation *ptr )
{
	return new SharedObject( ptr );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SharedObject::IncrementRefCount()
{
	_count++;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SharedObject::DecrementRefCount()
{
	_count--;
	if( _count < 0 )
	{
		_count = 0;
	}

	if( !_count )
	{
		delete _ptr;
		_ptr = NULL;

		delete this;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Interface::Implementation *SharedObject::Get() const
{
	return _ptr;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SharedObject::SharedObject( Interface::Implementation *ptr )
{
	_count = 1;
	_ptr = ptr;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SharedObject::SharedObject( const SharedObject &other )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SharedObject &SharedObject::operator=( const SharedObject &other )
{
	return *this;
}