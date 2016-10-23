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
		userVector.x += 30;
		break;
	case 'S' :
		userVector.x -= 30;
		break;
	case 'Q' :
		userVector.y -= 30;
		break;
	case 'D' :
		userVector.y += 30;
		break;
	default :
		userVector.Zero();
		break;
	}
}

void Leader::Update(double time_elapsed)
{
	userVector.x -= 10;
	userVector.y -= 10;
	if (userVector.x < 0)
		userVector.x = 0;
	if (userVector.y < 0)
		userVector.y = 0;
	Vehicle::Update(time_elapsed);
}
