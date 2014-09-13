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

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	class SharedObject
	{
	public:
		static SharedObject *Create( Interface::Implementation *ptr );

		void IncrementRefCount();
		void DecrementRefCount();
		Interface::Implementation *Get() const;
		
	private:
		SharedObject( Interface::Implementation *ptr );
		SharedObject( const SharedObject &other );
		SharedObject &operator=( const SharedObject &other );

		Interface::Implementation *	_ptr;
		int					_count;
	};

}

#endif // __SHAREDOBJECT_H__