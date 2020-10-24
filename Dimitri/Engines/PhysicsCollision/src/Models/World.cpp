#include "World.h"

PhysicsCollision::Models::World::World() {}

PhysicsCollision::Models::World::World(const float width, const float height)
{
	_world_facade = Facades::WorldFacade();
}

void PhysicsCollision::Models::World::add_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape)
{
	_world_facade.add_shape(shape);
}

void PhysicsCollision::Models::World::destroy_bodies()
{
	_world_facade.destroy_bodies();
}

void PhysicsCollision::Models::World::simulate()
{
	_world_facade.simulate();
}

std::map<std::shared_ptr<PhysicsCollision::Models::Shape>, b2Body*> PhysicsCollision::Models::World::get_world_bodies()
{
	return _world_facade.get_world_bodies();
}
