#include "WorldController.h"

Controllers::WorldController::WorldController() {
	_shapeController = ShapeController{};
}

void Controllers::WorldController::setup_world(float width, float height) {
	_world = Models::World{ width, height };
}

void Controllers::WorldController::clean_up()
{
}

Models::Shape Controllers::WorldController::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	Models::Shape* shape = _shapeController.create_shape(type, positions, is_dynamic);
	_world.add_shape(shape, x, y);
	return *shape;
}

void Controllers::WorldController::simulate()
{
	_world.simulate();
}
