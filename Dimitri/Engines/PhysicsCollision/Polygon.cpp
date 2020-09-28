#include "Shape.h"
#include "Polygon.h"

Polygon::Polygon()
{
	shapeAdapter = nullptr;
}

Polygon::Polygon(float width, float height)
{
	shapeAdapter = new ShapeAdapter{ "polygon" , width, height };
}
