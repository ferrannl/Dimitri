#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle()
{
	shapeAdapter = nullptr;
}

Triangle::Triangle(float x, float y, std::vector<std::pair<float, float>> position)
{
	this->x = x;
	this->y = y;
	shapeAdapter = new ShapeAdapter{"triangle" ,position };
}
