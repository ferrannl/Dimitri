#include "Shape.h"

Models::Shape::Shape()
{
	_shape_facade = nullptr;
}

std::shared_ptr<Facades::ShapeFacade> Models::Shape::get_shape_facade()const
{
	return _shape_facade;
}

float Models::Shape::get_x()const
{
	return _shape_facade->get_x();
}

float Models::Shape::get_y()const
{
	return _shape_facade->get_y();
}

float Models::Shape::get_angle()const
{
	return _shape_facade->get_angle();
}

void Models::Shape::move_x(const int value)const
{
	_shape_facade->move_x(value);
}

void Models::Shape::move_y()const
{
	_shape_facade->move_y();
}
