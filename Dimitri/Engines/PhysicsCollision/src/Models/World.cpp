#include "World.h"

Models::World::World() {}

Models::World::World(float width, float height)
{
	_world_facade = Facades::WorldFacade{ width, height };
}

void Models::World::add_shape(Shape* shape, float x, float y)
{
	_world_facade.add_shape(shape, x, y);
}

void Models::World::simulate()
{
	_world_facade.simulate();
}
