#pragma once
#include "Vehicle.h"
class Leader :
	public Vehicle
{
public:
	Leader(GameWorld* world,
		Vector2D position,
		double    rotation,
		Vector2D velocity);
	~Leader();

	void handleControl(WPARAM wParam);
};

