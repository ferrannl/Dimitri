#include "Shape.h"
#include "Polygon.h"

Polygon::Polygon()
{
	shapeAdapter = nullptr;
}

Polygon::Polygon(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	shapeAdapter = new ShapeAdapter{ "polygon" , width, height };
}
