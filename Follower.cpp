#include "Follower.h"
#include "Vehicle.h"
#include "SteeringBehaviors.h"
#include "ParamLoader.h"




Follower::Follower(GameWorld* world,
	Vector2D position,
	double    rotation,
	Vector2D velocity,
	Vehicle* pVehicle) : Vehicle (world,
								position, 
								rotation, 
								velocity, 
								Prm.VehicleMass,          //mass
								Prm.MaxSteeringForce,     //max force
								Prm.MaxSpeed,             //max velocity
								Prm.MaxTurnRatePerSecond, //max turn rate
								Prm.FollowerScale)        //scale
{
	this->Steering()->OffsetPursuitOn(pVehicle, Vector2D(0.0,1.0));
}



Follower::~Follower()
{
	
}
