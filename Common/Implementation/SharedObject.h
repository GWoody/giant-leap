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
		SharedObject( Interface::Implementation *ptr )
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
			if( _count < 0 )
			{
				_count = 0;
			}

			if( !_count )
			{
				delete _ptr;
				_ptr = NULL;
			}
		}

		Interface::Implementation *Get() const
		{
			return _ptr;
		}
		
	private:
		Interface::Implementation *	_ptr;
		int					_count;
	};

}

#endif // __SHAREDOBJECT_H__