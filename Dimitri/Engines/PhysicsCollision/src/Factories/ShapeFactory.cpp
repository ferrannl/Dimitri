#include "ShapeFactory.h"

Models::Shape Factories::ShapeFactory::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	if (type == "polygon") {
		return Models::Polygon(x, y, positions, is_dynamic);
	}
}
