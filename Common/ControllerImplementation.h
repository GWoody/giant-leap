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

namespace Leap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Frame` class.
	//-------------------------------------------------------------------------
	class ControllerImplementation : public Interface::Implementation
	{
	public:
		bool				isConnected() const;
		bool				isServiceConnected() const;
		bool				hasFocus() const;

		Controller::PolicyFlag	policyFlags() const;
		void				setPolicyFlags( Controller::PolicyFlag flags );

		bool				addListener( Listener &listener );
		bool				removeListener( Listener &listener );

		void				enableGesture( Gesture::Type type, bool enable );
		bool				isGestureEnabled( Gesture::Type type );
	};

}

#endif // __CONTROLLERIMPLEMENTATION_H__