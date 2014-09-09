/*
===============================================================================

	Giant Leap

	File	:	ListBaseImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the actual logic behind the `ListBase` class.

===============================================================================
*/

#include "Common.h"

#include "Leap.h"
#include "ListBaseImplementation.h"
using namespace Leap;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template<typename T>
ListBaseImplementation<T>::ListBaseImplementation()
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template<typename T>
int ListBaseImplementation<T>::count() const
{
	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template<typename T>
bool ListBaseImplementation<T>::isEmpty() const
{
	return true;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template<typename T>
T ListBaseImplementation<T>::operator[]( int index ) const
{
	return T();
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template<typename T>
ListBaseImplementation<T> &ListBaseImplementation<T>::append( const ListBaseImplementation<T> &other )
{
	breakpoint();
	return *this;
}