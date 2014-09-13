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
		FillConsoleOutputCharacter( GetStdHandle( STD_OUTPUT_HANDLE ), 0, 80 * 3, coord, NULL );

		cout << f.id() << endl;
		cout << "\t" << "Hand Count: " << f.hands().count() << endl;
		for( int i = 0; i < f.hands().count(); i++ )
		{
			Vector palmPosition = f.hands()[i].palmPosition();
			cout << "\t\t" << "Palm Position: " << palmPosition.x << ", " << palmPosition.y << ", " << palmPosition.z << endl;
		}
	}
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main( int argc, char **argv )
{
	Init init;
	TestListener l;
	Controller c;
	c.addListener( l );

	while( true );
	return 0;
}