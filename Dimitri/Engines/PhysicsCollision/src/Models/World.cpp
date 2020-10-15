#include "World.h"

Models::World::World() {}

Models::World::World(const float width, const float height)
{
	_world_facade = Facades::WorldFacade();
	_shapes = std::make_shared<std::vector<std::unique_ptr<Models::Shape>>>();
}

void Models::World::add_shape(Models::Shape shape, const float x, const float y)
{
	_shapes->push_back(std::make_unique<Shape>(shape));
	_world_facade.add_shape(_shapes->back(), x, y);
}

void Models::World::destroy_bodies()
{
	for (int i = 0; i < _shapes->size(); i++) {
		_world_facade.destroy_body(_shapes->at(i)->get_shape_facade());
	}
}

void Models::World::simulate()
{
	_world_facade.simulate();
}

std::shared_ptr<std::vector<std::unique_ptr<Models::Shape>>> Models::World::get_shapes() const
{
	return _shapes;
}
