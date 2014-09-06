/*
===============================================================================

	Giant Leap

	File	:	Interface.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the Giant Leap version of the `Interface` Leap SDK class.

===============================================================================
*/

#include "Leap.h"
#include "SharedObject.h"

using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface::Interface( Implementation* reference, void* owner )
{
	m_object = new SharedObject( reference );
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
	m_object->IncrementRefCount();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Interface &Interface::operator=( const Interface &rhs )
{
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
	return m_object->Get<Implementation>();
}