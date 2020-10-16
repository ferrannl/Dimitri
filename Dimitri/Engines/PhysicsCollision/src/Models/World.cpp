#include "World.h"

Models::World::World() {}

Models::World::World(const float width, const float height)
{
	_world_facade = Facades::WorldFacade();
}

void Models::World::add_shape(std::shared_ptr<Models::Shape> shape)
{
	_world_facade.add_shape(shape);
}

void Models::World::destroy_bodies()
{
	_world_facade.destroy_bodies();
}

void Models::World::simulate()
{
	_world_facade.simulate();
}
