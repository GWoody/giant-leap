/*
===============================================================================

	Giant Leap

	File	:	Pair.h
	Authors	:	Lucas Zadrozny
	Date	:	13th September 2014

	Purpose	:	Defines the interface->implementation pairing class.

===============================================================================
*/

#ifndef __PAIR_H__
#define __PAIR_H__

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Note: The implementation object MUST ALWAYS be allocated on the heap.
	//-------------------------------------------------------------------------
	template<typename Int_T, typename Imp_T>
	class Pair
	{
	public:
		Pair( Int_T &intr, Imp_T *implementation )
		{
			_interface = intr;
			_implementation = implementation;
		}

		Int_T GetInterface() const
		{
			return _interface;
		}

		Imp_T *GetImplementation() const
		{
			return _implementation;
		}

	private:
		Int_T				_interface;
		Imp_T *				_implementation;
	};

}

#endif // __PAIR_H__