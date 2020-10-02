#include "ShapeController.h"

Controllers::ShapeController::ShapeController()
{
	_shapeFactory = new Factories::ShapeFactory{};
}

Models::Shape Controllers::ShapeController::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	return _shapeFactory->create_shape(type, x, y, positions, is_dynamic);
}