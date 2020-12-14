#include "WorldController.h"
#include "../Enums/ShapeEnum.h"
using namespace PhysicsCollision;

Controllers::WorldController::WorldController() {
}

void Controllers::WorldController::setup_world(const float width, const float height) {
	_world = Models::World{ width, height };
}

void Controllers::WorldController::load_shape(const std::shared_ptr<PhysicsCollision::Models::Shape>& shape)
{
	_world.add_shape(shape);
}

void Controllers::WorldController::destroy_bodies()
{
	_world.destroy_bodies();
}

void PhysicsCollision::Controllers::WorldController::destroy_body(const std::shared_ptr<PhysicsCollision::Models::Shape>& shape)
{
	_world.destroy_body(shape);
}

void Controllers::WorldController::simulate(const float speed)const
{
	_world.simulate(speed);
}

std::vector<std::shared_ptr<Models::Shape>> Controllers::WorldController::get_shapes()const {
	return _world.get_shapes();
}
