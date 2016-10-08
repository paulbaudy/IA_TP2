#include "Leader.h"
#include "Vehicle.h"
#include "SteeringBehaviors.h"
#include "ParamLoader.h"



Leader::Leader(GameWorld* world,
	Vector2D position,
	double    rotation,
	Vector2D velocity) : Vehicle(world,
									position,
									rotation,
									velocity,
									Prm.VehicleMass,          //mass
									Prm.MaxSteeringForce,     //max force
									Prm.LeaderMaxSpeed,       //max velocity
									Prm.MaxTurnRatePerSecond, //max turn rate
									Prm.LeaderScale)         //scale
{
	this->Steering()->WanderOn();
}


Leader::~Leader()
{
}
