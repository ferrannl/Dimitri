#include "WorldController.h"
#include "../Enums/ShapeEnum.h"
using namespace PhysicsCollision;

Controllers::WorldController::WorldController() {
}

void Controllers::WorldController::setup_world(float width, float height) {
	_world = Models::World{ width, height };
}

void Controllers::WorldController::load_shape(const std::shared_ptr<PhysicsCollision::Models::Shape>& shape)
{
	_world.add_shape(shape);
}

void Controllers::WorldController::destroy_bodies() const
{
	_world.destroy_bodies();
}

void Controllers::WorldController::destroy_body(const std::shared_ptr<Models::Shape>& shape)
{
	_world.destroy_body(shape);
}

void Controllers::WorldController::simulate(float speed)const
{
	_world.simulate(speed);
}

const std::vector<std::shared_ptr<Models::Shape>>& Controllers::WorldController::get_shapes()const {
	return _world.get_shapes();
}
