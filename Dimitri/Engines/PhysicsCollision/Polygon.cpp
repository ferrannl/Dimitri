#include "Shape.h"
#include "Polygon.h"

Polygon::Polygon()
{
	shapeAdapter = nullptr;
}

Polygon::Polygon(float x, float y, std::vector<std::pair<float, float>> position)
{
	this->x = x;
	this->y = y;
	shapeAdapter = new ShapeAdapter{ "polygon" , position};
}
