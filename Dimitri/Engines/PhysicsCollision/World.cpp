#include "World.h"

World::World()
{
}

World::World(float width, float height)
{
	_worldAdapter = WorldAdapter{ width, height };
}

void World::add_shape(Shape shape)
{
	_worldAdapter.add_shape(shape);
}

void World::simulate()
{
	_worldAdapter.simulate();
}
