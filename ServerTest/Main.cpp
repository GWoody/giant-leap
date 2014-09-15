/*
===============================================================================

	Giant Leap

	File	:	Main.cpp
	Authors	:	Lucas Zadrozny
	Date	:	13th September 2014

	Purpose	:	Console application to test the server outside of a game engine.

===============================================================================
*/

#include "GiantLeap.h"
#include "Common.h"
#include "Implementation/FrameImplementation.h"
#include "Network/Socket.h"
using namespace GiantLeap;

#include <Windows.h>

#include <iomanip>
#include <iostream>
using namespace std;

#include "MemDebugOn.h"

class TestListener : public Listener
{
public:
	virtual void onFrame( const Controller &c )
	{
		const Frame &f = c.frame();

		// Clear the console.
		COORD coord; coord.X = coord.Y = 0;
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );

		cout << "Frame ID: " << f.id() << endl;
		cout << setprecision(3);

		cout << "\t" << "Hand Count: " << f.hands().count() << endl;
		for( int i = 0; i < f.hands().count(); i++ )
		{
			Vector palmPosition = f.hands()[i].palmPosition();
			cout << "\t\t" << "Palm Position: " << palmPosition.x << ", " << palmPosition.y << ", " << palmPosition.z << endl;
			cout << "\t\t" << "Finger Count: " << f.hands()[i].fingers().count() << endl;
			cout << "\t\t" << "Arm Direction: " << f.hands()[i].arm().direction().x << "\t" << f.hands()[i].arm().direction().y << "\t" << f.hands()[i].arm().direction().z << endl;
		}

		cout << "\t" << "Gesture Count: " << f.gestures().count() << endl;
		for( int i = 0; i < f.gestures().count(); i++ )
		{
			const char *TYPE_NAMES[] = { "", "TYPE_SWIPE", "", "", "TYPE_CIRCLE", "TYPE_SCREEN_TAP", "TYPE_KEY_TAP" };
			int type = f.gestures()[i].type();
			if( type < 1 || type > 6 )
				C_breakpoint();
			cout << "\t\t" << TYPE_NAMES[type] << endl;
		}
	}
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static void wait_for_exit()
{
	string str;

	do
	{
		//cout << "Type \"quit\" to exit the application: ";
		getline( cin, str );
	} while( str != "quit" );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main( int argc, char **argv )
{
	Init init;
	TestListener l;
	Controller c;
	c.addListener( l );

	wait_for_exit();

	return 0;
}