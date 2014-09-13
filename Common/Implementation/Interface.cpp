/*
===============================================================================

	Giant Leap

	File	:	Interface.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the Giant Leap version of the `Interface` Leap SDK class.

===============================================================================
*/

#include "GiantLeap.h"
#include "SharedObject.h"

using namespace GiantLeap;

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
	m_object->IncrementRefCount();
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
	m_object->DecrementRefCount();

	// Attach to the new pointer.
	m_object = rhs.m_object;
	m_object->IncrementRefCount();

	return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface::~Interface()
{
	m_object->DecrementRefCount();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface::Implementation *Interface::reference() const
{
	return m_object->Get();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Interface::deleteCString( const char *cstr )
{
	
}