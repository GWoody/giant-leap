/*
===============================================================================

	Giant Leap

	File	:	ControllerUnit.cpp
	Authors	:	Lucas Zadrozny
	Date	:	6th September 2014

	Purpose	:	`ControllerImplementation` unit tests.

===============================================================================
*/

#include "CommonUnit.h"

#include <Windows.h>

#include <iostream>
using namespace std;

#include "GiantLeap.h"
#include "Implementation/ControllerImplementation.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

//-----------------------------------------------------------------------------
// Tests.
//-----------------------------------------------------------------------------
IMPLEMENT_TEST_OBJECT( perform_policy_flag_test, ControllerImplementation, controller );
IMPLEMENT_TEST_OBJECT( perform_gesture_enable_test, ControllerImplementation, controller );
IMPLEMENT_TEST_OBJECT( perform_listener_test, ControllerImplementation, controller );

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool run_controller_test()
{
	ControllerImplementation *controller = new ControllerImplementation;

	TEST_OBJECT( "policy Flags", perform_policy_flag_test, controller );
	TEST_OBJECT( "gesture State", perform_gesture_enable_test, controller );
	TEST_OBJECT( "listener", perform_listener_test, controller );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST_OBJECT( perform_policy_flag_test, ControllerImplementation, controller )
{
	ASSERT( "Testing default policy flag", controller->policyFlags() == Controller::POLICY_DEFAULT );

	controller->setPolicyFlags( Controller::POLICY_BACKGROUND_FRAMES );
	ASSERT( "Testing background frame policy flag", controller->policyFlags() == Controller::POLICY_BACKGROUND_FRAMES );

	controller->setPolicyFlags( Controller::POLICY_DEFAULT );
	ASSERT( "Reverting to default policy flag", controller->policyFlags() == Controller::POLICY_DEFAULT );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
IMPLEMENT_TEST_OBJECT( perform_gesture_enable_test, ControllerImplementation, controller )
{
	// By default, all gestures should be disabled.
	ASSERT( "Testing default invalid gesture state", !controller->isGestureEnabled( Gesture::TYPE_INVALID ) );
	ASSERT( "Testing default swipe gesture state", !controller->isGestureEnabled( Gesture::TYPE_SWIPE ) );
	ASSERT( "Testing default circle gesture state", !controller->isGestureEnabled( Gesture::TYPE_CIRCLE ) );
	ASSERT( "Testing default screen tap gesture state", !controller->isGestureEnabled( Gesture::TYPE_SCREEN_TAP ) );
	ASSERT( "Testing default key tap gesture state", !controller->isGestureEnabled( Gesture::TYPE_KEY_TAP ) );

	// TODO: generate a dummy frame and ensure all gestures are invalid.

	const int GESTURE_COUNT = 4;
	const Gesture::Type GESTURE_INDICES[] = { Gesture::TYPE_SWIPE, Gesture::TYPE_CIRCLE, Gesture::TYPE_SCREEN_TAP, Gesture::TYPE_KEY_TAP };
	const char *GESTURE_NAMES[] = { "swipe", "circle", "screen tap", "key tap" };
	
	for( int i = 0; i < GESTURE_COUNT; i++ )
	{
		// Create strings we need.
		char enableString[64], disableString[64];
		_snprintf_s( enableString, sizeof(enableString), "Testing %s gesture enabled", GESTURE_NAMES[i] );
		_snprintf_s( disableString, sizeof(disableString), "Testing %s gesture disabled", GESTURE_NAMES[i] );

		controller->enableGesture( GESTURE_INDICES[i], true );
		ASSERT( enableString, controller->isGestureEnabled( GESTURE_INDICES[i] ) );

		// TODO: generate a dummy frame and ensure the swipe gesture is valid.

		controller->enableGesture( GESTURE_INDICES[i], false );
		ASSERT( disableString, !controller->isGestureEnabled( GESTURE_INDICES[i] ) );

		// TODO: generate a dummy frame and ensure the swipe gesture is invalid.
	}

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class ThreadedCounter
{
public:
	ThreadedCounter()
	{
		_mutex = CreateMutex( NULL, false, "name" );
		_count = 0;
	}

	~ThreadedCounter()
	{
		CloseHandle( _mutex );
	}

	void Increment()
	{
		WaitForSingleObject( _mutex, INFINITE );
			_count++;
		ReleaseMutex( _mutex );
	}

	void Decrement()
	{
		WaitForSingleObject( _mutex, INFINITE );
			_count--;
		ReleaseMutex( _mutex );
	}

	void Zero()
	{
		WaitForSingleObject( _mutex, INFINITE );
			_count = 0;
		ReleaseMutex( _mutex );
	}

	int Count()
	{
		WaitForSingleObject( _mutex, INFINITE );
			int c = _count;
		ReleaseMutex( _mutex );

		return c;
	}

private:
	HANDLE _mutex;
	int _count;
};

class UnitListener : public Listener
{
public:
	UnitListener( ThreadedCounter &connect, ThreadedCounter &frame ) :
		_connectionCount( connect ), _frameCount( frame )
	{
	}

	virtual void onInit( const Controller &c )
	{
		_connectionCount.Increment();
	}

	virtual void onFrame( const Controller &c )
	{
		_frameCount.Increment();
	}

	virtual void onExit( const Controller &c )
	{
		_connectionCount.Decrement();
	}

private:
	ThreadedCounter &_connectionCount;
	ThreadedCounter &_frameCount;
};

IMPLEMENT_TEST_OBJECT( perform_listener_test, ControllerImplementation, controller )
{
	const int LISTENER_COUNT = 3;

	ThreadedCounter connectionCount, frameCount;
	UnitListener *listeners[LISTENER_COUNT];

	for( int i = 0; i < LISTENER_COUNT; i++ )
	{
		listeners[i] = new UnitListener( connectionCount, frameCount );

		char adding[32], checking[64];
		_snprintf_s( adding, sizeof(adding), "Adding listener %d", i + 1 );
		_snprintf_s( checking, sizeof(checking), "Ensuring %d listeners are connected", i + 1 );

		ASSERT( adding, controller->addListener( *listeners[i] ) );
		ASSERT( checking, connectionCount.Count() == i + 1 );

		controller->DispatchFrame();
		ASSERT( "Sending dummy frame", frameCount.Count() == i + 1 );
		frameCount.Zero();
	}

	for( int i = LISTENER_COUNT - 1; i >= 0; i-- )
	{
		char removing[32], checking[64];
		_snprintf_s( removing, sizeof(removing), "Removing listener %d", i + 1 );
		_snprintf_s( checking, sizeof(checking), "Ensuring %d listeners are connected", i + 1 );

		ASSERT( removing, controller->removeListener( *listeners[i] ) );
		ASSERT( checking, connectionCount.Count() == i );

		controller->DispatchFrame();
		ASSERT( "Sending dummy frame", frameCount.Count() == i );
		frameCount.Zero();

		delete listeners[i];
	}

	ASSERT( "Ensuring no more listeners are connected", connectionCount.Count() == 0 );
	
	return true;
}