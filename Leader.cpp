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
	//this->Steering()->WanderOn();
	this->Steering()->UserControlOn();
	userVector.Zero();
}

Leader::~Leader()
{
}

void Leader::Update(double time_elapsed)
{
	if (VectorToLocalSpace(this->Velocity(), this->Heading(), this->Side()).x < 10 && userVector.x<0) {
		userVector.x = 0;
		userVector.y = 0;
		this->SetVelocity(Vector2D(0, 0));
	}

	Vehicle::Update(time_elapsed);
}
