#include "Shape.h"
#include "ShapeController.h"
#include "Polygon.h"

ShapeController::ShapeController()
{
	_shapeFactory = new ShapeFactory{};
}

Shape ShapeController::create_shape(std::string type,float x, float y, std::vector<std::pair<float, float>> position, bool is_dynamic)
{
	return _shapeFactory->create_shape(type,x,y,position, is_dynamic);
}