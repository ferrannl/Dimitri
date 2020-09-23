#include "Shape.h"
#include "ShapeController.h"
#include "Polygon.h"

ShapeController::ShapeController()
{
}

Shape ShapeController::create_shape(std::string type)
{
	return Polygon{};
}

bool ShapeController::has_collision(Shape shape1, Shape shape2)
{
	return false;
}
