#include "Shape.h"
#include "Square.h"

Square::Square()
{
	shapeAdapter = nullptr;
}

Square::Square(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	shapeAdapter = new ShapeAdapter{ "square", width, height };
}
