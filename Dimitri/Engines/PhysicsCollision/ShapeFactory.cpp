#include "ShapeFactory.h"

Shape ShapeFactory::create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> position)
{
	if (type == "polygon") {
		return Polygon(x,y,position);
	}
}
