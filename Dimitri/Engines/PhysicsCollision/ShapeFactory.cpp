#include "ShapeFactory.h"

Shape ShapeFactory::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> position, bool is_dynamic)
{
	if (type == "polygon") {
		return Polygon(x,y,position, is_dynamic);
	}
}
