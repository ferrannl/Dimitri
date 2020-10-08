#include "Shape.h"

Models::Shape::Shape()
{
	_shape_facade = nullptr;
}

void Models::Shape::add_body(Models::Body* body)
{
	_body = body;
}

Facades::ShapeFacade* Models::Shape::get_shape_facade()
{
	return _shape_facade;
}

float Models::Shape::get_x()
{
	return _body->get_x();
}

float Models::Shape::get_y()
{
	return _body->get_y();
}

float Models::Shape::get_angle()
{
	return _body->get_angle();
}
