#include "WorldController.h"

Controllers::WorldController::WorldController() {
	_shapeController = ShapeController{};
}

void Controllers::WorldController::setup_world(const float width, const float height) {
	_world = Models::World{ width, height };
}

Models::Shape Controllers::WorldController::create_shape(std::string type, float x, float y, float width, float height, bool is_dynamic)
{
	std::shared_ptr<Models::Shape> shape = _shapeController.create_shape(type,x,y, width, height, is_dynamic);
	_world.add_shape(shape);
	return *shape;
}

void Controllers::WorldController::destroy_bodies()
{
	_world.destroy_bodies();
}

void Controllers::WorldController::simulate()
{
	_world.simulate();
}
