#include "WorldController.h"

Controllers::WorldController::WorldController() {
	_shapeController = ShapeController{};
}

void Controllers::WorldController::setup_world(const float width, const float height) {
	_world = Models::World{ width, height };
}

void Controllers::WorldController::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	Models::Shape shape = _shapeController.create_shape(type, positions, is_dynamic);
	_world.add_shape(shape, x, y);
}

void Controllers::WorldController::destroy_bodies()
{
	_world.destroy_bodies();
}

void Controllers::WorldController::simulate()
{
	_world.simulate();
}

std::shared_ptr<std::vector<std::unique_ptr<Models::Shape>>> Controllers::WorldController::get_shapes()const {
	return _world.get_shapes();
}
