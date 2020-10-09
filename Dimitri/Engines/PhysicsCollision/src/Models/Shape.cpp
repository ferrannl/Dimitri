#include "Shape.h"

Models::Shape::Shape()
{
	_shape_facade = nullptr;
}

Facades::ShapeFacade* Models::Shape::get_shape_facade()
{
	return _shape_facade;
}

float Models::Shape::get_x()
{
	return _shape_facade->get_x();
}

float Models::Shape::get_y()
{
	return _shape_facade->get_y();
}

float Models::Shape::get_angle()
{
	return _shape_facade->get_angle();
}


void Models::Shape::set_x(int value)
{
	shapeAdapter->set_x(value);
}

void Models::Shape::set_y()
{
	shapeAdapter->set_y();
}
