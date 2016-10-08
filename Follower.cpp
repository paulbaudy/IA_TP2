#include "Follower.h"
#include "Vehicle.h"
#include "SteeringBehaviors.h"
#include "GameWorld.h"
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
	/*
	this->Steering()->OffsetPursuitOn(pVehicle, Vector2D(0.0,1.0));
	this->Steering()->SeparationOn();
	*/
	this->Steering()->WanderOn();
	this->Steering()->SeparationOn();
	isFollowing = false;
}

Follower::~Follower()
{
	
}



void Follower::Update(double time_elapsed){
	//if the vehicle isn't following another one, search for one
	if (!isFollowing) {
		World()->CellSpace()->CalculateNeighbors(this->Pos(), 50.0);
		for (Vehicle* pV = World()->CellSpace()->begin(); !World()->CellSpace()->end(); pV = World()->CellSpace()->next())
		{
			if (this != pV && this != pV->Steering()->GetTarget1() && pV->getFollowedBy()==nullptr) {
				this->Steering()->OffsetPursuitOn(pV, Vector2D(20.0, 20.0));
				pV->setFollower(this);
				isFollowing = true;
				this->Steering()->WanderOff();
				break;
			}
		}
	}
	Vehicle::Update(time_elapsed);
}

