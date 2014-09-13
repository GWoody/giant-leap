/*
===============================================================================

	Giant Leap

	File	:	ControllerImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	Implements the actual logic behind the `Controller` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "ControllerImplementation.h"
using namespace GiantLeap;

#include <iostream>
using namespace std;

#include "MemDebugOn.h"

ControllerImplementation *ControllerImplementation::_instance = NULL;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ControllerImplementation::ControllerImplementation()
{
	if( _instance )
	{
		cout << "WARNING: Created more than 1 controller instance!" << endl;
	}
	_instance = this;

	_policyFlags = Controller::POLICY_DEFAULT;
	_gestureState = 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::isConnected() const
{
	C_breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::isServiceConnected() const
{
	C_breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::hasFocus() const
{
	C_breakpoint();
	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Controller::PolicyFlag ControllerImplementation::policyFlags() const
{
	return (Controller::PolicyFlag)_policyFlags;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ControllerImplementation::setPolicyFlags( Controller::PolicyFlag flags )
{
	_policyFlags = flags;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::addListener( Listener &listener )
{
	_listeners.push_back( &listener );

	// Notify the instance of the connection.
	Controller c( this );
	listener.onInit( c );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::removeListener( Listener &listener )
{
	// Notify the instance of the disconnection.
	Controller c( this );
	listener.onExit( c );

	_listeners.remove( &listener );
	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Frame ControllerImplementation::frame( int history )
{
	history = C_clamp( history, 0, 60 );
	return Frame( &_frames[history] );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ControllerImplementation::enableGesture( Gesture::Type type, bool enable )
{
	if( type != Gesture::TYPE_INVALID )
	{
		if( enable )
		{
			_gestureState |= ( 1 << type );
		}
		else
		{
			_gestureState &= ~( 1 << type );
		}
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool ControllerImplementation::isGestureEnabled( Gesture::Type type )
{
	if( type != Gesture::TYPE_INVALID )
	{
		return ( _gestureState & ( 1 << type ) ) ? true : false;
	}

	return false;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ControllerImplementation::DispatchFrame()
{
	Controller c( this );
	
	for each( Listener *listener in _listeners )
	{
		listener->onFrame( c );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ControllerImplementation::PushFrame( const FrameImplementation &frame )
{
	while( _frames.size() >= 60 )
	{
		_frames.pop_back();
	}

	_frames.push_front( frame );
}