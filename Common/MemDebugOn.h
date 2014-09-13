/*
===============================================================================

	Giant Leap

	File	:	MemDebugOn.h
	Authors	:	Lucas Zadrozny
	Date	:	13th September 2014

	Purpose	:	.

===============================================================================
*/

#ifndef __MEMDEBUGON_H__
#define __MEMDEBUGON_H__

#ifdef _DEBUG
	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif

#endif // __MEMDEBUGON_H__