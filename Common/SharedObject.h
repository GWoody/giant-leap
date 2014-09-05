/*
===============================================================================

	Giant Leap

	File	:	SharedObject.h
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the Giant Leap version of the `SharedObject` Leap SDK class.

===============================================================================
*/

#ifndef __SHAREDOBJECT_H__
#define __SHAREDOBJECT_H__

namespace Leap
{

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	class SharedObject
	{
	public:
		SharedObject( void *ptr )
		{
			_count = 1;
			_ptr = ptr;
		}

		void IncrementRefCount()
		{
			_count++;
		}

		void DecrementRefCount()
		{
			_count--;
			if( !_count )
			{
				delete this;
			}
		}

		template<typename T> T *Get() const
		{
			return static_cast<T *>( _ptr );
		}
		
	private:
		void *				_ptr;
		int					_count;
	};

}

#endif // __SHAREDOBJECT_H__