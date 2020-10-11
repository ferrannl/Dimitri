#include "WorldController.h"

Controllers::WorldController::WorldController() {
	_shapeController = ShapeController{};
}

void Controllers::WorldController::setup_world(const float width, const float height) {
	_world = Models::World{ width, height };
}

Models::Shape Controllers::WorldController::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	std::shared_ptr<Models::Shape> shape = _shapeController.create_shape(type, positions, is_dynamic);
	_world.add_shape(shape, x, y);
	return *shape;
}

void Controllers::WorldController::destroy()
{
	_world.destroy_bodies();
}

void Controllers::WorldController::simulate()
{
	_world.simulate();
}
