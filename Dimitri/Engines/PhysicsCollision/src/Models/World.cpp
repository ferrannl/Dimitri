#include "World.h"

PhysicsCollision::Models::World::World() {}

PhysicsCollision::Models::World::World(const float width, const float height)
{
	_world_facade = Facades::WorldFacade();
	_shapes = std::vector<std::shared_ptr<Models::Shape>>();
}

void PhysicsCollision::Models::World::add_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape)
{
	_shapes.push_back(shape);
	_world_facade.add_shape(shape);
}

void PhysicsCollision::Models::World::destroy_bodies()
{
	for (int i = 0; i < _shapes.size(); i++) {
		_world_facade.destroy_body(_shapes.at(i)->get_shape_facade());
	}
}

void PhysicsCollision::Models::World::simulate()
{
	_world_facade.simulate();
}

std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> PhysicsCollision::Models::World::get_shapes()const
{
	return _shapes;
}
