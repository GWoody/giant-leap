/*
===============================================================================

	Giant Leap

	File	:	HandImplementation.cpp
	Authors	:	Lucas Zadrozny
	Date	:	10th September 2014

	Purpose	:	Implements the actual logic behind the `Hand` class.

===============================================================================
*/

#include "Common.h"

#include "GiantLeap.h"
#include "HandImplementation.h"
#include "ListBaseImplementation.h"
#include "FrameImplementation.h"
using namespace GiantLeap;

#include "MemDebugOn.h"

IdMap_t global_hand_id_map;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation::HandImplementation() :
	_arm( Arm(), NULL )
{

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation::HandImplementation( const Leap::Hand &hand ) :
	_arm( Arm(), NULL )
{
	FromLeap( hand );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation::HandImplementation( BufferRead *buffer ) :
	_arm( Arm(), NULL )
{
	Unserialize( buffer );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::FromLeap( const Leap::Hand &hand )
{
	//
	// Read misc.
	//
	_id = hand.id();
	_palmPosition = hand.palmPosition();
	_stabilizedPalmPosition = hand.stabilizedPalmPosition();
	_palmVelocity = hand.palmVelocity();
	_palmNormal = hand.palmNormal();
	_palmWidth = hand.palmWidth();
	_direction = hand.direction();
	_sphereCenter = hand.sphereCenter();
	_sphereRadius = hand.sphereRadius();
	_pinchStrength = hand.pinchStrength();
	_grabStrength = hand.grabStrength();
	_confidence = hand.confidence();
	_isLeft = hand.isLeft();

	//
	// Read fingers.
	//
	const Leap::FingerList &fingers = hand.fingers();
	for( int i = 0; i < fingers.count(); i++ )
	{
		FingerImplementation *fi = new FingerImplementation( fingers[i] );
		Finger f( fi );

		_fingers.push_back( FingerPair_t( f, fi ) );
	}

	//
	// Read arm.
	//
	ArmImplementation *ai = new ArmImplementation( hand.arm() );
	Arm a( ai );
	_arm = ArmPair_t( a, ai );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::Serialize( BufferWrite *buffer )
{
	buffer->WriteInt( 'hand' );

	//
	// Write misc.
	//
	buffer->WriteInt( _id );
	buffer->WriteVector( _palmPosition );
	buffer->WriteVector( _stabilizedPalmPosition );
	buffer->WriteVector( _palmVelocity );
	buffer->WriteVector( _palmNormal );
	buffer->WriteFloat( _palmWidth );
	buffer->WriteVector( _direction );
	buffer->WriteVector( _sphereCenter );
	buffer->WriteFloat( _sphereRadius );
	buffer->WriteFloat( _pinchStrength );
	buffer->WriteFloat( _grabStrength );
	buffer->WriteFloat( _confidence );
	buffer->WriteShort( _isLeft );

	//
	// Write fingers.
	//
	buffer->WriteInt( _fingers.size() );
	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		_fingers[i].GetImplementation()->Serialize( buffer );
	}

	//
	// Write arm.
	//
	_arm.GetImplementation()->Serialize( buffer );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::Unserialize( BufferRead *buffer )
{
	_fingers.clear();
	if( buffer->ReadInt() != 'hand' )
	{
		std::cout << "Expected 'hand', got junk." << std::endl;
		return false;
	}

	//
	// Read misc.
	//
	_id = buffer->ReadInt();
	_palmPosition = buffer->ReadVector();
	_stabilizedPalmPosition = buffer->ReadVector();
	_palmVelocity = buffer->ReadVector();
	_palmNormal = buffer->ReadVector();
	_palmWidth = buffer->ReadFloat();
	_direction = buffer->ReadVector();
	_sphereCenter = buffer->ReadVector();
	_sphereRadius = buffer->ReadFloat();
	_pinchStrength = buffer->ReadFloat();
	_grabStrength = buffer->ReadFloat();
	_confidence = buffer->ReadFloat();
	_isLeft = buffer->ReadShort() != 0 ? true : false;

	//
	// Read fingers.
	//
	unsigned int fingers = buffer->ReadInt();
	for( unsigned int i = 0; i < fingers; i++ )
	{
		FingerImplementation *fi = new FingerImplementation();
		if( !fi->Unserialize( buffer ) )
		{
			Con_Printf( "HandImplementation::Unserialize - failed to read finger\n" );
			delete fi;
			return false;
		}

		Finger f( fi );
		_fingers.push_back( FingerPair_t( f, fi ) );
	}

	//
	// Read arm.
	//
	ArmImplementation *ai = new ArmImplementation();
	if( !ai->Unserialize( buffer ) )
	{
		return false;
	}

	Arm a( ai );
	_arm = ArmPair_t( a, ai );

	return true;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::Translate( const Vector &v )
{
	_palmPosition += v;
	_stabilizedPalmPosition += v;
	_sphereCenter += v;

	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		_fingers[i].GetImplementation()->Translate( v );
	}

	_arm.GetImplementation()->Translate( v );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::Rotate( const Matrix &pry )
{
	_palmPosition = pry.transformDirection( _palmPosition );
	_stabilizedPalmPosition = pry.transformDirection( _stabilizedPalmPosition );
	_palmVelocity = pry.transformDirection( _palmVelocity );
	_palmNormal = pry.transformDirection( _palmNormal );
	_direction = pry.transformDirection( _direction );
	_sphereCenter = pry.transformDirection( _sphereCenter );

	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		_fingers[i].GetImplementation()->Rotate( pry );
	}

	_arm.GetImplementation()->Rotate( pry );
}

//-----------------------------------------------------------------------------
// Takes a single hand as seen from multiple devices.
// `this` and `rhs` represent the same hand.
// `thisFrame` is the frame to which `this` belongs.
// `rhsFrame` is the frame to which `rhs` belongs.
//-----------------------------------------------------------------------------
void HandImplementation::Merge( const FrameImplementation &thisFrame, const FrameImplementation &rhsFrame, const HandImplementation &rhs )
{
	IdMap_t::iterator it = global_hand_id_map.find( _id );
	if( it != global_hand_id_map.end() )
	{
		// This frame was previously merged into another. Take on the old ID.
		_id = it->second;
	}
	else
	{
		// Store the RHS frame ID that we are merging.
		global_hand_id_map[rhs._id] = _id;
	}

	// Calculate the distance between each hand-frame pair.
	// As the confidence of each hand approaches 0, make the distance large.
	float thisDistance = _palmPosition.distanceTo( thisFrame.GetDeviceTranslation() ) * ( 1.0f / _confidence );
	float rhsDistance = rhs._palmPosition.distanceTo( rhsFrame.GetDeviceTranslation() ) * ( 1.0f / rhs._confidence );

	float thisWeight = CalculateWeight( *this, thisFrame, thisDistance, rhs, rhsDistance );
	float rhsWeight = CalculateWeight( rhs, rhsFrame, rhsDistance, *this, thisDistance );

	// Merge all local variables.
	InternalMerge( thisWeight, rhs, rhsWeight );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation HandImplementation::operator+( const HandImplementation &rhs ) const
{
	HandImplementation h;

	C_breakpoint();

	//
	// Merge general.
	//
	h._id = std::min( _id, rhs._id );
	h._palmPosition = _palmPosition + rhs._palmPosition;
	h._stabilizedPalmPosition = _stabilizedPalmPosition + rhs._stabilizedPalmPosition;
	h._palmVelocity = _palmVelocity + rhs._palmVelocity;
	h._palmNormal = _palmNormal + rhs._palmNormal;
	h._palmWidth = _palmWidth + rhs._palmWidth;
	h._direction = _direction + rhs._direction;
	h._sphereCenter = _sphereCenter + rhs._sphereCenter;
	h._sphereRadius = _sphereRadius + rhs._sphereRadius;
	h._pinchStrength = _pinchStrength + rhs._pinchStrength;
	h._grabStrength = _grabStrength + rhs._grabStrength;
	h._confidence = _confidence + rhs._confidence;

	//
	// Merge fingers.
	//
	for( int i = 0; i < 5; i++ )
	{
		Finger::Type type = (Finger::Type)i;
		FingerImplementation *thisFinger = GetFingerByType( type );
		FingerImplementation *rhsFinger = rhs.GetFingerByType( type );

		if( !thisFinger && !rhsFinger )
		{
			continue;
		}

		FingerImplementation *newFinger = new FingerImplementation();
		Finger f( newFinger );
		if( thisFinger && rhsFinger )
		{
			(*newFinger) = (*thisFinger) + (*rhsFinger);
		}
		else if( thisFinger )
		{
			(*newFinger) = (*thisFinger);
		}
		else if( rhsFinger )
		{
			(*newFinger) = (*rhsFinger);
		}

		h._fingers.push_back( FingerPair_t( f, newFinger ) );
	}

	//
	// Merge arm.
	//
	ArmImplementation *newArm = new ArmImplementation;
	Arm a( newArm );
	(*newArm) = (*_arm.GetImplementation()) + (*rhs._arm.GetImplementation());

	h._arm = ArmPair_t( a, newArm );

	return h;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation HandImplementation::operator*( float scale ) const
{
	HandImplementation h;

	C_breakpoint();

	h._id = _id;
	h._palmPosition = _palmPosition * scale;
	h._stabilizedPalmPosition = _stabilizedPalmPosition * scale;
	h._palmVelocity = _palmVelocity * scale;
	h._palmNormal = _palmNormal * scale;
	h._palmWidth = _palmWidth * scale;
	h._direction = _direction * scale;
	h._sphereCenter = _sphereCenter * scale;
	h._sphereRadius = _sphereRadius * scale;
	h._pinchStrength = _pinchStrength * scale;
	h._grabStrength = _grabStrength * scale;
	h._confidence = _confidence * scale;

	//
	// Merge fingers.
	//
	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		FingerImplementation *thisFinger = _fingers[i].GetImplementation();
		FingerImplementation *newFinger = new FingerImplementation();
		Finger f( newFinger );

		(*newFinger) = (*thisFinger) * scale;

		h._fingers.push_back( FingerPair_t( f, newFinger ) );
	}

	//
	// Merge arm.
	//
	ArmImplementation *newArm = new ArmImplementation;
	Arm a( newArm );
	(*newArm) = (*_arm.GetImplementation()) * scale;
	h._arm = ArmPair_t( a, newArm );

	return h;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HandImplementation HandImplementation::operator/( float scale ) const
{
	HandImplementation h;

	C_breakpoint();

	//
	// Merge misc.
	//
	h._id = _id;
	h._palmPosition = _palmPosition / scale;
	h._stabilizedPalmPosition = _stabilizedPalmPosition / scale;
	h._palmVelocity = _palmVelocity / scale;
	h._palmNormal = _palmNormal / scale;
	h._palmWidth = _palmWidth / scale;
	h._direction = _direction / scale;
	h._sphereCenter = _sphereCenter / scale;
	h._sphereRadius = _sphereRadius / scale;
	h._pinchStrength = _pinchStrength / scale;
	h._grabStrength = _grabStrength / scale;
	h._confidence = _confidence / scale;

	//
	// Merge fingers.
	//
	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		FingerImplementation *thisFinger = _fingers[i].GetImplementation();
		FingerImplementation *newFinger = new FingerImplementation();
		Finger f( newFinger );

		(*newFinger) = (*thisFinger) / scale;

		h._fingers.push_back( FingerPair_t( f, newFinger ) );
	}

	//
	// Merge arm.
	//
	ArmImplementation *newArm = new ArmImplementation;
	Arm a( newArm );
	(*newArm) = (*_arm.GetImplementation()) / scale;
	h._arm = ArmPair_t( a, newArm );

	return h;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int32_t HandImplementation::id() const
{
	return _id;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Frame HandImplementation::frame() const
{
	C_breakpoint();
	return Frame();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::palmPosition() const
{
	return _palmPosition;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::stabilizedPalmPosition() const
{
	return _stabilizedPalmPosition;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::palmVelocity() const
{
	return _palmVelocity;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::palmNormal() const
{
	return _palmNormal;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::palmWidth() const
{
	return _palmWidth;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::direction() const
{
	return _direction;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix HandImplementation::basis() const
{
	C_breakpoint();
	return Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Arm HandImplementation::arm() const
{
	return _arm.GetInterface();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::wristPosition() const
{
	C_breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::sphereCenter() const
{
	return _sphereCenter;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::sphereRadius() const
{
	return _sphereRadius;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::pinchStrength() const
{
	return _pinchStrength;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::grabStrength() const
{
	return _grabStrength;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::timeVisible() const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::confidence() const
{
	return _confidence;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::isLeft() const
{
	return _isLeft;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool HandImplementation::isRight() const
{
	return !_isLeft;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PointableList HandImplementation::pointables() const
{
	C_breakpoint();
	return PointableList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Pointable HandImplementation::pointable( int32_t id ) const
{
	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		if( _fingers[i].GetImplementation()->id() == id )
		{
			return _fingers[i].GetInterface();
		}
	}

	return Pointable::invalid();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerList HandImplementation::fingers() const
{
	ListBaseImplementation<Finger> *list = new ListBaseImplementation<Finger>;

	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		list->push_back( _fingers[i].GetInterface() );
	}

	return FingerList( *list );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Finger HandImplementation::finger( int32_t id ) const
{
	C_breakpoint();
	return Finger();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ToolList HandImplementation::tools() const
{
	C_breakpoint();
	return ToolList();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Tool HandImplementation::tool( int32_t id ) const
{
	C_breakpoint();
	return Tool();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::translation( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::translationProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Vector HandImplementation::rotationAxis( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Vector();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationAngle( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationAngle( const Frame &sinceFrame, const Vector& axis ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Matrix HandImplementation::rotationMatrix( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return Matrix::identity();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::rotationProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::scaleFactor( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::scaleProbability( const Frame &sinceFrame ) const
{
	C_breakpoint();
	return 0.0f;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
const char * HandImplementation::toCString() const
{
	C_breakpoint();
	return "";
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FingerImplementation *HandImplementation::GetFingerByType( Finger::Type type ) const
{
	for( unsigned int i = 0; i < _fingers.size(); i++ )
	{
		if( _fingers[i].GetImplementation()->type() == type )
		{
			return _fingers[i].GetImplementation();
		}
	}

	return NULL;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
float HandImplementation::CalculateWeight( const HandImplementation &target, const FrameImplementation &targetFrame, float targetDistance, const HandImplementation &other, float otherDistance ) const
{
	// The closer the target hand is to the target device, the higher it will be weighted.
	float weight = ( otherDistance / targetDistance );

	// The closer the target hands palm normal is to the `hand->device` vector, the higher it will be weighted.
	Vector handDeviceDir = target._palmPosition - targetFrame.GetDeviceTranslation();
	handDeviceDir = handDeviceDir.normalized();
	float cosTheta = target._palmNormal.dot( handDeviceDir ) / ( target._palmNormal.magnitude() * handDeviceDir.magnitude() );

	weight *= fabs( cosTheta );

	return weight;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void HandImplementation::InternalMerge( float thisWeight, const HandImplementation &rhs, float rhsWeight )
{
	const float totalWeight = thisWeight + rhsWeight;

	_palmPosition = MergeVar( _palmPosition, thisWeight, rhs._palmPosition, rhsWeight );
	_stabilizedPalmPosition = MergeVar( _stabilizedPalmPosition, thisWeight, rhs._stabilizedPalmPosition, rhsWeight );
	_palmVelocity = MergeVar( _palmVelocity, thisWeight, rhs._palmVelocity, rhsWeight );
	_palmNormal = MergeVar( _palmNormal, thisWeight, rhs._palmNormal, rhsWeight );
	_palmWidth = MergeVar( _palmWidth, thisWeight, rhs._palmWidth, rhsWeight );
	_direction = MergeVar( _direction, thisWeight, rhs._direction, rhsWeight );
	_sphereCenter = MergeVar( _sphereCenter, thisWeight, rhs._sphereCenter, rhsWeight );
	_sphereRadius = MergeVar( _sphereRadius, thisWeight, rhs._sphereRadius, rhsWeight );
	_pinchStrength = MergeVar( _pinchStrength, thisWeight, rhs._pinchStrength, rhsWeight );
	_grabStrength = MergeVar( _grabStrength, thisWeight, rhs._grabStrength, rhsWeight );
	_confidence = MergeVar( _confidence, thisWeight, rhs._confidence, rhsWeight );

	(*_arm.GetImplementation()) = MergeVar( (*_arm.GetImplementation()), thisWeight, (*rhs._arm.GetImplementation()), rhsWeight );

	for( unsigned int i = 0; i < 5; i++ )
	{
		*_fingers[i].GetImplementation() = MergeVar( (*_fingers[i].GetImplementation()), thisWeight, (*rhs._fingers[i].GetImplementation()), rhsWeight );
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template<typename T> T HandImplementation::MergeVar( const T &x, float xWeight, const T &y, float yWeight )
{
	return ( (x * xWeight) + (y * yWeight) ) / ( xWeight + yWeight );
}