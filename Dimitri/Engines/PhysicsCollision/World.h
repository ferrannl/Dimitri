#pragma once

#include "WorldAdapter.h"
#include "Shape.h"

class World {
private:
	WorldAdapter _worldAdapter;
public:
	World();
	World(float width, float height);
	void add_shape(Shape shape);
	void simulate();
};