#include "ShapeController.h"
#include "../Enums/ShapeEnum.h"
using namespace PhysicsCollision;

Controllers::ShapeController::ShapeController()
{
}

std::shared_ptr<Models::Shape> Controllers::ShapeController::create_shape(const PhysicsCollision::Enums::ShapeEnum type, float x, float y, float width, float height, const bool is_dynamic) const
{
	std::shared_ptr<Models::Shape> shape;
	switch (type) {
	case Enums::ShapeEnum::Square:
		shape = std::make_shared<Models::Square>();
		break;
	case Enums::ShapeEnum::Polygon:
		shape = std::make_shared<Models::Polygon>();
	}
	shape->set_height(height);
	shape->set_width(width);
	shape->set_x(x);
	shape->set_y(y);
	shape->set_type(type);
	shape->set_is_dynamic(is_dynamic);
	return shape;
}
