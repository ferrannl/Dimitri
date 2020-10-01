#include "WorldController.h"

WorldController::WorldController() {
	_shapeController = ShapeController{};
}

void WorldController::setup_world(float width, float height) {
	_world = World{ width, height };
}

void WorldController::clean_up()
{
}

void WorldController::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> position)
{
	Shape shape = _shapeController.create_shape(type,x,y, position);
	_world.add_shape(shape);
}

void WorldController::simulate()
{
	_world.simulate();
}
