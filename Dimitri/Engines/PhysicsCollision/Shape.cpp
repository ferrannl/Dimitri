#include "Shape.h"

Shape::Shape()
{
	shapeAdapter = nullptr;
}

void Shape::add_body(b2Body* body)
{
	shapeAdapter->add_body(body);
}

float Shape::get_x()
{
	return shapeAdapter->get_x();
}

float Shape::get_y()
{
	return shapeAdapter->get_y();
}
