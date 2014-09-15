/*
===============================================================================

	Giant Leap

	File	:	ArmImplementation.h
	Authors	:	Gareth Woodorth
	Date	:   9th September 2014

	Purpose	:	Implements the Giant Leap version of the `Arm` Leap SDK class.

===============================================================================
*/

#ifndef __ARMIMPLEMENTATION_H__
#define __ARMIMPLEMENTATION_H__

#include "Network/Buffer.h"
#include "Pair.h"

namespace GiantLeap
{
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	class ArmImplementation : public Interface::Implementation
	{
	public:
		ArmImplementation();
		ArmImplementation( const Leap::Arm &arm );
		ArmImplementation( BufferRead *buffer );

		// Initialization.
		virtual void		FromLeap( const Leap::Arm &arm );

		// Networking.
		virtual bool		Serialize( BufferWrite *buffer );
		virtual bool		Unserialize( BufferRead *buffer );

		// Manipulations.
		virtual void		Translate( const Vector &v );
		virtual void		Rotate( const Vector &v );

		// Leap interface.

		float				width() const;
		Vector				direction() const;
		Matrix				basis() const;
		Vector				elbowPosition() const;
		Vector				wristPosition() const;
		const char *		toCString() const;

	private:
		float				_width;
		Vector				_elbowPosition;
		Vector				_wristPosition;
	};

}

#endif // __ARMIMPLEMENTATION_H__