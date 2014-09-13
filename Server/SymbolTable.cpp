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

#pragma comment( linker, "/include:??0Controller@GiantLeap@@QAE@XZ" )