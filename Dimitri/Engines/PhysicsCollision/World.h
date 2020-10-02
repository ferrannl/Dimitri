#pragma once

#include "WorldAdapter.h"
#include "Shape.h"

class __declspec(dllexport) World
{
private:
	WorldAdapter _worldAdapter;
public:
	World();
	World(float width, float height);
	void add_shape(Shape shape);
	void simulate();
};