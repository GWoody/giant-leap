/*
===============================================================================

	Giant Leap

	File	:	PointableImplementation.h
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the real logic behind the `Pointable` class.

===============================================================================
*/

#ifndef __POINTABLEIMPLEMENTATION_H__
#define __POINTABLEIMPLEMENTATION_H__

#include "Network/Buffer.h"
#include "Pair.h"

namespace GiantLeap
{

	//-------------------------------------------------------------------------
	// Contains the "real" data for the Leap `Pointable` class.
	//-------------------------------------------------------------------------
	class PointableImplementation : public Interface::Implementation
	{
	public:
		PointableImplementation();
		PointableImplementation( const Leap::Pointable &pointable );
		PointableImplementation( BufferRead *buffer );

		// Initialization.
		virtual void		FromLeap( const Leap::Pointable &pointable );

		// Networking.
		virtual bool		Serialize( BufferWrite *buffer );
		virtual bool		Unserialize( BufferRead *buffer );

		// Manipulations.
		virtual void		Translate( const Vector &v );
		virtual void		Rotate( const Vector &v );

		// Leap interface.
		int32_t				id() const;
		Frame				frame() const;
		Hand				hand() const;
		Vector				tipPosition() const;
		Vector				stabilizedTipPosition() const;
		Vector				tipVelocity() const;
		Vector				direction() const;
		float				width() const;
		float				length() const;
		float				timeVisible() const;

		bool				isFinger() const;
		bool				isTool() const;
		bool				isExtended() const;

		Pointable::Zone		touchZone() const;
		float				touchDistance() const;

		const char *		toCString() const;

	private:
		int32_t				_id;
		Vector				_tipPosition;
		Vector				_stabilizedTipPosition;
		Vector				_tipVelocity;
		Vector				_direction;
		float				_width;
		float				_length;
	};

}

#endif // __POINTABLEIMPLEMENTATION_H__