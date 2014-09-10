/*
===============================================================================

	Giant Leap

	File	:	ToolList.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the Giant Leap version of the `ToolList` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "ListBaseImplementation.h"
#include "SharedObject.h"
using namespace Leap;

typedef ListBaseImplementation<Tool> ListType_t;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ToolList::ToolList() : Interface( (SharedObject *)NULL )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ToolList::ToolList( const ListType_t &list ) : Interface( (Interface::Implementation *)&list, this )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int ToolList::count() const
{
	return get<ListType_t>()->count();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool ToolList::isEmpty() const
{
	return get<ListType_t>()->isEmpty();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Tool ToolList::operator[](int index) const
{
	return (*get<ListType_t>())[index];
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ToolList &ToolList::append( const ToolList &other )
{
	get<ListType_t>()->append( *other.get<ListType_t>() );
	return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Tool ToolList::leftmost() const
{
	breakpoint();
	return Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Tool ToolList::rightmost() const
{
	breakpoint();
	return Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Tool ToolList::frontmost() const
{
	breakpoint();
	return Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ToolList::const_iterator ToolList::begin() const
{
	breakpoint();
	return const_iterator( *this, 0 );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT ToolList::const_iterator ToolList::end() const
{
	breakpoint();
	return const_iterator( *this, count() );
}