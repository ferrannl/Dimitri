#include "World.h"

Models::World::World() {}

Models::World::World(const float width, const float height)
{
	_world_facade = Facades::WorldFacade();
}

void Models::World::add_shape(std::shared_ptr<Shape> shape, const float x, const float y)
{
	_world_facade.add_shape(shape, x, y);
}

void Models::World::destroy_bodies()
{
	_world_facade.destroy();
}

void Models::World::simulate()
{
	_world_facade.simulate();
}
