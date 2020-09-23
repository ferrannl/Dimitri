#include "Shape.h"
#include "Polygon.h"

Polygon::Polygon()
{
	_shapeAdapter = ShapeAdapter{ "polygon" };
}
