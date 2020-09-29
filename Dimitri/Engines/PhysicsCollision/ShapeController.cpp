#include "Shape.h"
#include "ShapeController.h"
#include "Polygon.h"

ShapeController::ShapeController()
{
	_shapeFactory = new ShapeFactory{};
}

Shape ShapeController::create_shape(std::string type, float x, float y, float width, float height)
{
	return _shapeFactory->create_shape(type, x, y, width, height);
}

bool ShapeController::has_collision(Shape shape1, Shape shape2)
{
	return false;
}
