#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle()
{
	shapeAdapter = nullptr;
}

Triangle::Triangle(float width, float height)
{
	shapeAdapter = new ShapeAdapter{ "triangle", width, height };
}
