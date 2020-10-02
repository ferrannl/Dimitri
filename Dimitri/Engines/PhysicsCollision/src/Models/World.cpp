#include "World.h"

Models::World::World() {}

Models::World::World(float width, float height)
{
	_worldAdapter = Adapters::WorldAdapter{ width, height };
}

void Models::World::add_shape(Shape shape, float x, float y)
{
	_worldAdapter.add_shape(shape, x, y);
}

void Models::World::simulate()
{
	_worldAdapter.simulate();
}
