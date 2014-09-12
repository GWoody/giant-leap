/*
===============================================================================

	Giant Leap

	File	:	Main.cpp
	Authors	:	Lucas Zadrozny
	Date	:	5th September 2014

	Purpose	:	High level Giant Leap functionality.

===============================================================================
*/

#include "Common.h"
#include "Network/Socket.h"
#include "Implementation/FrameImplementation.h"

#include "GiantLeap.h"
using namespace GiantLeap;

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class ClientListener : public Leap::Listener
{
public:
	virtual void onFrame( const Leap::Controller &controller );
};

//-----------------------------------------------------------------------------
// Prototypes.
//-----------------------------------------------------------------------------
static string get_target_ip_address();
static Leap::Vector get_device_translation();
static Leap::Vector get_device_rotation();
static void wait_for_exit();

//-----------------------------------------------------------------------------
// Global variables.
//-----------------------------------------------------------------------------
static string global_server_address;
static Leap::Vector global_device_translation, global_device_rotation;
static UdpSocket global_socket( false, GIANT_LEAP_PORT );

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main( int argc, char **argv )
{
	//
	// Gather networking information.
	//
	global_server_address = get_target_ip_address();

	//
	// Build the device information.
	//
	global_device_translation = get_device_translation();
	global_device_rotation = get_device_rotation();

	//
	// Setup the Leap Motion.
	//
	ClientListener listener;
	Leap::Controller controller( listener );

	cout << endl;
	cout << "Leap Motion initialized!" << endl;
	cout << "Sending frame data to " << global_server_address << ":" << GIANT_LEAP_PORT << endl;
	cout << endl;

	wait_for_exit();

	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static string get_target_ip_address()
{
	string address;

	cout << "Enter the IP address of the target machine: ";
	getline( cin, address );

	return address;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static Leap::Vector get_device_translation()
{
	string str;

	cout << "Enter device translation [right up back]: ";
	getline( cin, str );

	return string_to_vector( str );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static Leap::Vector get_device_rotation()
{
	string str;

	cout << "Enter device rotation [pitch roll yaw]: ";
	getline( cin, str );

	return string_to_vector( str );
}

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
void ClientListener::onFrame( const Leap::Controller &controller )
{
	// Make a copy of the Leap Motion frame we can manipulate.
	FrameImplementation frame( controller.frame() );

	// Transform the data for the server.
	frame.Rotate( global_device_rotation );
	frame.Translate( global_device_translation );

	// Write the frame into a contiguous block of memory.
	BufferWrite buf = frame.Serialize();

	// Send the frame to the server.
	global_socket.Send( buf.Get(), buf.GetLength(), global_server_address.c_str() );
}