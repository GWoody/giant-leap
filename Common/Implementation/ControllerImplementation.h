/*
===============================================================================

	Giant Leap

	File	:	ControllerImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the real logic behind the `Controller` class.

===============================================================================
*/

#ifndef __CONTROLLERIMPLEMENTATION_H__
#define __CONTROLLERIMPLEMENTATION_H__

#include <list>

namespace Leap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Controller` class.
	//-------------------------------------------------------------------------
	class ControllerImplementation : public Interface::Implementation
	{
	public:
		ControllerImplementation();

		bool				isConnected() const;
		bool				isServiceConnected() const;
		bool				hasFocus() const;

		Controller::PolicyFlag	policyFlags() const;
		void				setPolicyFlags( Controller::PolicyFlag flags );

		bool				addListener( Listener &listener );
		bool				removeListener( Listener &listener );

		void				enableGesture( Gesture::Type type, bool enable );
		bool				isGestureEnabled( Gesture::Type type );

		// Unit Testing.
		// TODO: `GenerateDummyFrame()` to test `_gestureState`.
		void				DispatchDummyFrame();

	private:
		uint32_t			_policyFlags;
		uint32_t			_gestureState;

		std::list<Listener *>	_listeners;
	};

}

#endif // __CONTROLLERIMPLEMENTATION_H__