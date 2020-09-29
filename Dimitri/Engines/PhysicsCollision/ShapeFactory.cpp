#include "ShapeFactory.h"

Shape ShapeFactory::create_shape(std::string type, float x, float y, float width, float height)
{
	if (type == "polygon") {
		return Polygon(x, y, width, height);
	}
	else if (type == "triangle") {
		return Triangle(x, y, width, height);
	}
	return Square(x, y, width, height);
}
