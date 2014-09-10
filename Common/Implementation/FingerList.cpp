/*
===============================================================================

	Giant Leap

	File	:	FingerList.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the Giant Leap version of the `FingerList` Leap SDK class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "ListBaseImplementation.h"
#include "SharedObject.h"
using namespace Leap;

typedef ListBaseImplementation<Finger> ListType_t;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList::FingerList() : Interface( (SharedObject *)NULL )
{
	
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerList::FingerList( const ListBaseImplementation<Finger> &list ) : Interface( (Interface::Implementation *)&list, this )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT int FingerList::count() const
{
	return get<ListType_t>()->count();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT bool FingerList::isEmpty() const
{
	return get<ListType_t>()->isEmpty();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger FingerList::operator[](int index) const
{
	return (*get<ListType_t>())[index];
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList &FingerList::append( const FingerList &other )
{
	get<ListType_t>()->append( *other.get<ListType_t>() );
	return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger FingerList::leftmost() const
{
	breakpoint();
	return Finger();
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger FingerList::rightmost() const
{
	breakpoint();
	return Finger();
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT Finger FingerList::frontmost() const
{
	breakpoint();
	return Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList &FingerList::extended()
{
	breakpoint();
	return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList &FingerList::fingerType( Finger::Type type )
{
	breakpoint();
	return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList::const_iterator FingerList::begin() const
{
	return const_iterator( *this, 0 );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
LEAP_EXPORT FingerList::const_iterator FingerList::end() const
{
	return const_iterator( *this, count() );
}