/*
===============================================================================

	Giant Leap

	File	:	Main.cpp
	Authors	:	Lucas Zadrozny
	Date	:	13th September 2014

	Purpose	:	God awful symbol inclusions.
				Apparently /OPT:NOREF doesn't work on the `Common.lib` symbols,
				so we must manually include symbols that are being stripped.

				This code makes me sad :(

===============================================================================
*/

#include "Timer.h"

#pragma comment( linker, "/include:??0Controller@GiantLeap@@QAE@XZ" )
#pragma comment( linker, "/include:??0Timer@GiantLeap@@QAE@_N@Z" )
#pragma comment( linker, "/include:??0SwipeGesture@GiantLeap@@QAE@ABVGesture@1@@Z" )
#pragma comment( linker, "/include:??0CircleGesture@GiantLeap@@QAE@ABVGesture@1@@Z" )
#pragma comment( linker, "/include:??0ScreenTapGesture@GiantLeap@@QAE@ABVGesture@1@@Z" )
#pragma comment( linker, "/include:??0KeyTapGesture@GiantLeap@@QAE@ABVGesture@1@@Z" )