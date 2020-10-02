#include "Shape.h"

Models::Shape::Shape()
{
	shapeAdapter = nullptr;
}

void Models::Shape::add_body(b2Body* body)
{
	shapeAdapter->add_body(body);
}

float Models::Shape::get_x()
{
	return shapeAdapter->get_x();
}

float Models::Shape::get_y()
{
	return shapeAdapter->get_y();
}
