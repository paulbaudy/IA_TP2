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
	// this->Steering()->WanderOn();
	userVector.Zero();
}

Leader::~Leader()
{
}

void Leader::handleControl(WPARAM wParam) {
	switch(wParam) {
	case 'Z' : 
		userVector.x = 100;
		break;
	case 'Q' :
		userVector.y = -100;
		break;
	case 'D' :
		userVector.y = 100;
		break;
	default :
		userVector.Zero();
		break;
	}
}

void Leader::handleControlUp(WPARAM wParam) {
	switch (wParam) {
	case 'Z':
		userVector.x = -100;
		break;
	case 'Q':
	case 'D':
		userVector.y = 0;
		break;
	default:
		userVector.Zero();
		break;
	}
}



void Leader::Update(double time_elapsed)
{
	if (VectorToLocalSpace(this->Velocity(), this->Heading(), this->Side()).x < 1 && userVector.x<0) {
		userVector.x = 0;
	}

	Vehicle::Update(time_elapsed);
}
