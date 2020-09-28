#include "ShapeFactory.h"

Shape ShapeFactory::create_shape(std::string type, float width, float height)
{
	if (type == "polygon") {
		return Polygon(width, height);
	}
	else if (type == "triangle") {
		return Triangle(width, height);
	}
	return Square(width, height);
}
