#include "WorldController.h"

PhysicsCollision::Controllers::WorldController::WorldController() {
	_shapeController = ShapeController{};
}

void PhysicsCollision::Controllers::WorldController::setup_world(const float width, const float height) {
	_world = Models::World{ width, height };
}

PhysicsCollision::Models::Shape PhysicsCollision::Controllers::WorldController::create_shape(std::string type, float x, float y, float width, float height, bool is_dynamic)
{
	std::shared_ptr<Models::Shape> shape = _shapeController.create_shape(type,x,y, width, height, is_dynamic);
	_world.add_shape(shape);
	return *shape;
}

void PhysicsCollision::Controllers::WorldController::destroy_bodies()
{
	_world.destroy_bodies();
}

void PhysicsCollision::Controllers::WorldController::simulate()
{
	_world.simulate();
}

std::shared_ptr<std::vector<std::unique_ptr<PhysicsCollision::Models::Shape>>> PhysicsCollision::Controllers::WorldController::get_shapes()const {
	return _world.get_shapes();
}
