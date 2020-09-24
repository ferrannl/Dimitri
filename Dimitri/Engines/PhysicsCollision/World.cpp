#include "World.h"

World::World()
{
	_worldAdapter = WorldAdapter{};
}

void World::add_shape(Shape shape)
{
	_worldAdapter.add_shape(shape);
}

void World::simulate()
{
	_worldAdapter.simulate();
}
