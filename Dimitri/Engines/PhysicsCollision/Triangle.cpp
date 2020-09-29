#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle()
{
	shapeAdapter = nullptr;
}

Triangle::Triangle(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	shapeAdapter = new ShapeAdapter{ "triangle", width, height };
}
