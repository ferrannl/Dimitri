#include "WorldController.h"
#include "../Enums/ShapeEnum.h"
using namespace PhysicsCollision;

Controllers::WorldController::WorldController() {
	_shapeController = ShapeController{};
}

void Controllers::WorldController::setup_world(const float width, const float height) {
	_world = Models::World{ width, height };
}

std::shared_ptr<Models::Shape> Controllers::WorldController::create_shape(PhysicsCollision::Enums::ShapeEnum type, float x, float y, float width, float height, bool is_dynamic, bool is_interactable)
{
	std::shared_ptr<Models::Shape> shape = _shapeController.create_shape(type,x,y, width, height, is_dynamic, is_interactable);
	_world.add_shape(shape);
	return shape;
}

bool Controllers::WorldController::check_collision(std::shared_ptr<Models::Shape> shape1, std::shared_ptr<Models::Shape> shape2)
{
	if (shape1->get_x() - 1 <= shape2->get_x() + shape2->get_width() &&
		shape1->get_x() + shape1->get_width() + 1 >= shape2->get_x() &&
		shape1->get_y() - 1 <= shape2->get_y() + shape2->get_height() &&
		shape1->get_y() + shape1->get_height() + 1 >= shape2->get_y()) {
		return true;
	}
	return false;
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
