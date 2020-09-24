#pragma once

#include "WorldAdapter.h"
#include "Shape.h"

class World {
private:
	WorldAdapter _worldAdapter;
public:
	World();
	void add_shape(Shape shape);
	void simulate();
};