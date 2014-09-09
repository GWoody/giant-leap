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

namespace Leap
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
	};

}

#endif // __LISTBASEIMPLEMENTATION_H__