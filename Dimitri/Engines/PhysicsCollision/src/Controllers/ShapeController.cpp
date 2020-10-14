#include "ShapeController.h"

Controllers::ShapeController::ShapeController()
{
	_shape_factory = std::make_shared<Factories::ShapeFactory>();
}

std::shared_ptr<Models::Shape> Controllers::ShapeController::create_shape(const std::string type, const std::vector<std::pair<float, float>> positions, const bool is_dynamic) const
{
	return _shape_factory->create_shape(type, positions, is_dynamic);
}