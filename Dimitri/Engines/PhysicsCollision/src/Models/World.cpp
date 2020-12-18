#include "World.h"
using namespace PhysicsCollision;

Models::World::World() {}

Models::World::World(float width, float height)
{
	_world_facade = std::make_shared<Facades::WorldFacade>();
	_shapes = std::vector<std::shared_ptr<Models::Shape>>();
}

void Models::World::add_shape(const std::shared_ptr<Models::Shape> shape)
{
	_shapes.push_back(shape);
	_world_facade->add_shape(shape);
}

void Models::World::destroy_bodies()const
{
	for (int i = 0; i < _shapes.size(); i++) {
		_world_facade->destroy_body(_shapes.at(i)->get_shape_facade());
	}
}

void PhysicsCollision::Models::World::destroy_body(const std::shared_ptr<Models::Shape> shape)
{
	_shapes.erase(std::remove(_shapes.begin(), _shapes.end(), shape), _shapes.end());
	_world_facade->destroy_body(shape->get_shape_facade());
}

void Models::World::simulate(float speed)const
{
	_world_facade->simulate(speed);
}

const std::vector<std::shared_ptr<Models::Shape>>& Models::World::get_shapes()const
{
	return _shapes;
}
