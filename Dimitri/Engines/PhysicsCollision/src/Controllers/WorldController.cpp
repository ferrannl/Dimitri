#include "WorldController.h"
#include "../Enums/ShapeEnum.h"
using namespace PhysicsCollision;

Controllers::WorldController::WorldController() {
}

void Controllers::WorldController::setup_world(const float width, const float height) {
	_world = Models::World{ width, height };
}

void Controllers::WorldController::load_shapes(std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> shapes)
{
	for(auto shape : shapes)
	{
		_world.add_shape(shape);
	}
}

void Controllers::WorldController::destroy_bodies()
{
	_world.destroy_bodies();
}

void Controllers::WorldController::simulate()
{
	_world.simulate();
}

std::vector<std::shared_ptr<Models::Shape>> Controllers::WorldController::get_shapes()const {
	return _world.get_shapes();
}
