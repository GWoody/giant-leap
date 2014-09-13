/*
===============================================================================

	Giant Leap

	File	:	HandList.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the Giant Leap version of the `HandList` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "ListBaseImplementation.h"
#include "SharedObject.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

typedef ListBaseImplementation<Hand> ListType_t;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT HandList::HandList() : Interface( (SharedObject *)NULL )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandList::HandList( const ListBaseImplementation<Hand> &list ) : Interface( (Interface::Implementation *)&list, this )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int HandList::count() const
{
	return get<ListType_t>()->count();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool HandList::isEmpty() const
{
	return get<ListType_t>()->isEmpty();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Hand HandList::operator[](int index) const
{
	return (*get<ListType_t>())[index];
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT HandList &HandList::append( const HandList &other )
{
	get<ListType_t>()->append( *other.get<ListType_t>() );
	return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Hand HandList::leftmost() const
{
	C_breakpoint();
	return Hand();
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Hand HandList::rightmost() const
{
	C_breakpoint();
	return Hand();
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Hand HandList::frontmost() const
{
	C_breakpoint();
	return Hand();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT HandList::const_iterator HandList::begin() const
{
	return const_iterator( *this, 0 );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT HandList::const_iterator HandList::end() const
{
	return const_iterator( *this, count() );
}