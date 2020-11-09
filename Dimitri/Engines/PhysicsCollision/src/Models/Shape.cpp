#include "Shape.h"
using namespace PhysicsCollision;

Models::Shape::Shape()
{
	_shape_facade = std::make_shared<Facades::ShapeFacade>();
}

std::shared_ptr<Facades::ShapeFacade> Models::Shape::get_shape_facade()const
{
	return _shape_facade;
}

Enums::ShapeEnum Models::Shape::get_type()const
{
	return _type;
}

void Models::Shape::set_type(Enums::ShapeEnum type)
{
	_type = type;
}

void Models::Shape::set_x(float x)
{
	_x = x;
}

void Models::Shape::set_y(float y)
{
	_y = y;
}

void Models::Shape::set_width(float width)
{
	_width = width;
}

void Models::Shape::set_height(float height)
{
	_height = height;
}

float Models::Shape::get_x()const
{
	return _x;
}

float Models::Shape::get_y()const
{
	return _y;
}

float Models::Shape::get_width()const
{
	return _width;
}

float Models::Shape::get_height()const
{
	return _height;
}

float Models::Shape::get_angle()const
{
	return 0;
}

bool Models::Shape::get_is_dynamic()const
{
	return _is_dynamic;
}

bool Models::Shape::get_is_interactable()const
{
	return _is_interactable;
}

void Models::Shape::set_is_dynamic(bool is_dynamic)
{
	_is_dynamic = is_dynamic;
}

void PhysicsCollision::Models::Shape::set_is_interactable(bool is_interactable)
{
	_is_interactable = is_interactable;
}

void Models::Shape::move_x(const int value)const
{
	_shape_facade->move_x(value);
}

void Models::Shape::move_y()const
{
	_shape_facade->move_y();
}
