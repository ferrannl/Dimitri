#include "WorldController.h"

WorldController::WorldController() {
	_shapeController = ShapeController{};
	setup_world();
}

void WorldController::setup_world() {
	_world = World{};
}

void WorldController::clean_up()
{
}

void WorldController::create_shape(std::string type)
{
	Shape shape = _shapeController.create_shape(type);
	_world.add_shape(shape);
}

void WorldController::simulate()
{
	_world.simulate();
}
