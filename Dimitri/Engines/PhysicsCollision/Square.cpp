#include "Shape.h"
#include "Square.h"

Square::Square()
{
	shapeAdapter = nullptr;
}

Square::Square(float x, float y, std::vector<std::pair<float, float>> position)
{
	this->x = x;
	this->y = y;
	shapeAdapter = new ShapeAdapter{ "square", position };
}
