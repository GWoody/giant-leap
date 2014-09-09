/*
===============================================================================

	Giant Leap

	File	:	GestureList.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the Giant Leap version of the `GestureList` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "ListBaseImplementation.h"
#include "SharedObject.h"
using namespace Leap;

typedef ListBaseImplementation<Gesture> ListType_t;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
GestureList::GestureList( const ListBaseImplementation<Gesture> &list ) : Interface( (Interface::Implementation *)&list, this )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int GestureList::count() const
{
	return get<ListType_t>()->count();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool GestureList::isEmpty() const
{
	return get<ListType_t>()->isEmpty();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Gesture GestureList::operator[](int index) const
{
	return (*get<ListType_t>())[index];
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GestureList &GestureList::append( const GestureList &other )
{
	get<ListType_t>()->append( *other.get<ListType_t>() );
	return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GestureList::const_iterator GestureList::begin() const
{
	breakpoint();
	return const_iterator( *this, 0 );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT GestureList::const_iterator GestureList::end() const
{
	breakpoint();
	return const_iterator( *this, count() );
}