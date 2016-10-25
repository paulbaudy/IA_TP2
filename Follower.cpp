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
	this->previous = pVehicle;
	this->Steering()->WanderOn();
	this->Steering()->SeparationOn();
}

Follower::~Follower()
{
	
}

void Follower::Update(double time_elapsed){
	//if the vehicle isn't following another one, search for one
	if (isFollowing == nullptr) {
		World()->CellSpace()->CalculateNeighbors(this->Pos(), 125.0);
		Vehicle* pV = World()->CellSpace()->begin();
		if (!World()->CellSpace()->end()) { //If some neighbors where found
			do {
				if (this != pV && this != pV->Steering()->GetTarget1() && validFollow(pV)) {
					Follow(pV);
					break;
				}
				pV = World()->CellSpace()->next();
			} while (!World()->CellSpace()->end());
		}

	}
	Vehicle::Update(time_elapsed);
}

void Follower::Follow(Vehicle * toFollow)
{
	toFollow->setFollower(this);
	isFollowing = toFollow;
	this->Steering()->WanderOff();
	this->Steering()->OffsetPursuitOn(toFollow, Vector2D(-20.0, 0.0));
}

void Follower::ChangeToManualResearch()
{
	Follow(previous);
}

void Follower::ChangeToAutoResearch()
{
	//Re-init follow
	if (isFollowing != nullptr) {
		isFollowing->setFollower(nullptr);
		isFollowing = nullptr;
	}
	this->Steering()->WanderOn();
	this->Steering()->OffsetPursuitOff();
}

void Follower::ChangeToFlockingV(Vehicle* agent, const Vector2D offset) {

	agent->setFollower(this);
	isFollowing = agent;

	this->Steering()->WanderOff();
	this->Steering()->SeparationOff();

	this->Steering()->FlockingVOn(agent, offset);
}