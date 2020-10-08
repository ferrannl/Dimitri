#include "ShapeController.h"

Controllers::ShapeController::ShapeController()
{
	_shape_factory = new Factories::ShapeFactory{};
}

Models::Shape* Controllers::ShapeController::create_shape(std::string type, std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	return _shape_factory->create_shape(type, positions, is_dynamic);
}