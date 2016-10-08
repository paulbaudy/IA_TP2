#pragma once
#include "Vehicle.h"
#include "Leader.h"


class Follower :
	public Vehicle
{
public:
	Follower(GameWorld* world,
		Vector2D position,
		double    rotation,
		Vector2D velocity,
		Vehicle* pVehicle);
	~Follower();
	void Update(double time_elapsed);
	
private:
	
};

