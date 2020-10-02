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

Shape WorldController::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> position, bool is_dynamic)
{
	Shape shape = _shapeController.create_shape(type,x,y, position, is_dynamic);
	_world.add_shape(shape);
	return shape;
}

void WorldController::simulate()
{
	_world.simulate();
}
