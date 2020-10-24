#include "Shape.h"

PhysicsCollision::Models::Shape::Shape()
{
	_shape_facade = std::make_shared<PhysicsCollision::Facades::ShapeFacade>();
}

std::shared_ptr<PhysicsCollision::Facades::ShapeFacade> PhysicsCollision::Models::Shape::get_shape_facade()const
{
	return _shape_facade;
}

std::string PhysicsCollision::Models::Shape::get_type()
{
	return _type;
}

void PhysicsCollision::Models::Shape::set_type(std::string type)
{
	_type = type;
}

void PhysicsCollision::Models::Shape::set_x(float x)
{
	_x = x;
}

void PhysicsCollision::Models::Shape::set_y(float y)
{
	_y = y;
}

void PhysicsCollision::Models::Shape::set_width(float width)
{
	_width = width;
}

void PhysicsCollision::Models::Shape::set_height(float height)
{
	_height = height;
}

float PhysicsCollision::Models::Shape::get_x()const
{
	return _x;
}

float PhysicsCollision::Models::Shape::get_y()const
{
	return _y;
}

float PhysicsCollision::Models::Shape::get_width()const
{
	return _width;
}

float PhysicsCollision::Models::Shape::get_height()const
{
	return _height;
}

float PhysicsCollision::Models::Shape::get_angle()const
{
	return 0;
}

bool PhysicsCollision::Models::Shape::get_is_dynamic()const
{
	return _is_dynamic;
}

void PhysicsCollision::Models::Shape::set_is_dynamic(bool is_dynamic)
{
	_is_dynamic = is_dynamic;
}

void PhysicsCollision::Models::Shape::move_x(const int value)const
{
	_shape_facade->move_x(value);
}

void PhysicsCollision::Models::Shape::move_y()const
{
	_shape_facade->move_y();
}
