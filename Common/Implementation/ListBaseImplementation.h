/*
===============================================================================

	Giant Leap

	File	:	ListBaseImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	9th September 2014

	Purpose	:	Implements the real logic behind the `ListBase` class.

===============================================================================
*/

#ifndef __LISTBASEIMPLEMENTATION_H__
#define __LISTBASEIMPLEMENTATION_H__

#include <vector>

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Frame` class.
	//-------------------------------------------------------------------------
	template<typename T>
	class ListBaseImplementation : public Interface::Implementation
	{
		typedef ListBaseImplementation<T> ThisType_t;

	public:
		ListBaseImplementation();

		int					count() const;
		bool				isEmpty() const;
		T					operator[]( int index ) const;
		ThisType_t &		append( const ThisType_t &other );

		void				push_back( const T &element );

	private:
		std::vector<T>		_list;
	};

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
		return _list.size();
	}

	//-----------------------------------------------------------------------------
	//-----------------------------------------------------------------------------
	template<typename T>
	bool ListBaseImplementation<T>::isEmpty() const
	{
		return _list.size() == 0;
	}

	//-----------------------------------------------------------------------------
	//-----------------------------------------------------------------------------
	template<typename T>
	T ListBaseImplementation<T>::operator[]( int index ) const
	{
		return _list[index];
	}

	//-----------------------------------------------------------------------------
	//-----------------------------------------------------------------------------
	template<typename T>
	ListBaseImplementation<T> &ListBaseImplementation<T>::append( const ListBaseImplementation<T> &other )
	{
		C_breakpoint();
		return *this;
	}

	//-----------------------------------------------------------------------------
	//-----------------------------------------------------------------------------
	template<typename T>
	void ListBaseImplementation<T>::push_back( const T &element )
	{
		_list.push_back( element );
	}

}

#endif // __LISTBASEIMPLEMENTATION_H__