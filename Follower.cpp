#include "Follower.h"
#include "Vehicle.h"
#include "SteeringBehaviors.h"
#include "ParamLoader.h"



Follower::Follower(GameWorld* world,
	Vector2D position,
	double    rotation,
	Vector2D velocity,
	Leader* pLeader) : Vehicle (world, 
								position, 
								rotation, 
								velocity, 
								Prm.VehicleMass,          //mass
								Prm.MaxSteeringForce,     //max force
								Prm.MaxSpeed,             //max velocity
								Prm.MaxTurnRatePerSecond, //max turn rate
								Prm.FollowerScale)        //scale
{
	this->Steering()->FlockingOn();
	this->Steering()->EvadeOn(pLeader);
}



Follower::~Follower()
{
	
}
