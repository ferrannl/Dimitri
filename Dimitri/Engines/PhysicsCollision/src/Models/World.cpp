#include "World.h"

Models::World::World() {}

Models::World::World(const float width, const float height)
{
	_world_facade = Facades::WorldFacade();
	//_shapes = std::make_shared<std::vector<std::shared_ptr<Shape>>>();
}

//void Models::World::add_shape_to_shapes(std::shared_ptr<Shape> shape)
//{
//	_shapes->push_back(shape);
//}

void Models::World::add_shape(std::shared_ptr<Shape> shape, const float x, const float y)
{
	_world_facade.add_shape(shape, x, y);
}

void Models::World::destroy_shapes()
{
	
}

void Models::World::simulate()
{
	_world_facade.simulate();
}
