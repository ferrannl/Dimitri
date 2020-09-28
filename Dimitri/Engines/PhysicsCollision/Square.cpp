#include "Shape.h"
#include "Square.h"

Square::Square()
{
	shapeAdapter = nullptr;
}

Square::Square(float width, float height)
{
	shapeAdapter = new ShapeAdapter{ "square", width, height };
}
