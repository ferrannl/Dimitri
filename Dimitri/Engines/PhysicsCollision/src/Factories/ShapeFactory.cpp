#include "ShapeFactory.h"

Models::Shape* Factories::ShapeFactory::create_shape(std::string type, std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	if (type == "polygon") {
		return new Models::Polygon(positions, is_dynamic);
	}
}
