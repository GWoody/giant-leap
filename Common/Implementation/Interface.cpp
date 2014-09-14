/*
===============================================================================

	Giant Leap

	File	:	Interface.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the Giant Leap version of the `Interface` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "SharedObject.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface::Interface( Implementation* reference, void* owner )
{
	m_object = SharedObject::Create( reference );

	if( reference == owner )
	{
		// If we aren't the owner of the object, then we have acquired it.
		m_object->IncrementRefCount();
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface::Interface( const Interface &rhs )
{
	m_object = rhs.m_object;
	if( m_object )
	{
		m_object->IncrementRefCount();
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Interface::Interface( SharedObject *object )
{
	m_object = object;
	if( m_object )
	{
		m_object->IncrementRefCount();
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface &Interface::operator=( const Interface &rhs )
{
	// Signal that we are releasing the old pointer.
	if( m_object )
	{
		m_object->DecrementRefCount();
	}

	// Attach to the new pointer.
	m_object = rhs.m_object;
	if( m_object )
	{
		m_object->IncrementRefCount();
	}

	return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface::~Interface()
{
	if( m_object )
	{
		m_object->DecrementRefCount();
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface::Implementation *Interface::reference() const
{
	return m_object ? m_object->Get() : NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Interface::deleteCString( const char *cstr )
{
	
}