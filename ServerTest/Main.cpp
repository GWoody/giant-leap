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

		cout << endl;

		FillConsoleOutputCharacter( GetStdHandle( STD_OUTPUT_HANDLE ), 0, 80, coord, NULL );
		cout << "\t" << "Frame ID: " << f.id() << "\t\t" << "Hand Count: " << f.hands().count() << endl;

		if( !f.hands().count() )
		{
			for( int i = 0; i < 6; i++ )
				cout << "                                                                             " << endl;
		}

		for( int i = 0; i < f.hands().count(); i++ )
		{
			Vector palmPosition = f.hands()[i].palmPosition();

			FillConsoleOutputCharacter( GetStdHandle( STD_OUTPUT_HANDLE ), 0, 80, coord, NULL );
			cout << "\t\t" << "Palm Position: " << palmPosition.x << ", " << palmPosition.y << ", " << palmPosition.z << endl;

			FillConsoleOutputCharacter( GetStdHandle( STD_OUTPUT_HANDLE ), 0, 80, coord, NULL );
			cout << "\t\t" << "Finger Count: " << f.hands()[i].fingers().count() << endl;

			FillConsoleOutputCharacter( GetStdHandle( STD_OUTPUT_HANDLE ), 0, 80, coord, NULL );
			cout << "\t\t" << "Arm Direction: " << f.hands()[i].arm().direction().x << "\t" << f.hands()[i].arm().direction().y << "\t" << f.hands()[i].arm().direction().z << endl;

			FillConsoleOutputCharacter( GetStdHandle( STD_OUTPUT_HANDLE ), 0, 80, coord, NULL );
			cout << "\t\t" << "Gesture Count: " << f.gestures().count() << endl;
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
		cout << "Type \"quit\" to exit the application: ";
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