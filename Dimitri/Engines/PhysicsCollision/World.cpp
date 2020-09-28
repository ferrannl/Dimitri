#include "World.h"

World::World()
{
}

World::World(float width, float height)
{
	_worldAdapter = WorldAdapter{ width, height };
}

void World::add_shape(Shape shape, float x, float y)
{
	_worldAdapter.add_shape(shape, x, y);
}

void World::simulate()
{
	_worldAdapter.simulate();
}
