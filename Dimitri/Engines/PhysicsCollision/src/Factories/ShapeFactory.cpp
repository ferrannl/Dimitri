#include "ShapeFactory.h"

std::shared_ptr<Models::Shape> Factories::ShapeFactory::create_shape(const std::string type, const std::vector<std::pair<float, float>> positions, const bool is_dynamic)const
{
	if (type == "polygon") {
		return std::make_shared<Models::Polygon>(positions, is_dynamic);
	}
}
