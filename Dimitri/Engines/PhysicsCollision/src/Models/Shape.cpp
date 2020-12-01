#include "Shape.h"
using namespace PhysicsCollision;

Models::Shape::Shape(const int x, const int y, const int height, const int width, const bool is_dynamic, const bool is_interactable, const Enums::ShapeEnum type) : _type{ type }, _height{ height }, _width{ width }, _x{ x }, _y{ y }, _is_dynamic{ is_dynamic }, _is_interactable{ is_interactable }
{
	_angle = 0;
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

void Models::Shape::set_is_interactable(bool is_interactable)
{
	_is_interactable = is_interactable;
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

void PhysicsCollision::Models::Shape::set_angle(float angle)
{
	_angle = angle;
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
	return _angle;
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

void Models::Shape::move_x(const int value)const
{
	_shape_facade->move_x(value);
}

void Models::Shape::move_y()const
{
	_shape_facade->move_y();
}

bool Models::Shape::check_square_collision(std::shared_ptr<Models::Shape> shape)
{
	return get_x() - 1 <= shape->get_x() + shape->get_width() &&
		get_x() + get_width() + 1 >= shape->get_x() &&
		get_y() - 1 <= shape->get_y() + shape->get_height() &&
		get_y() + get_height() + 1 >= shape->get_y();
}

bool Models::Shape::check_bottom_collision(std::shared_ptr<Models::Shape> shape)
{
	const int collision_height = 1;
	return get_x() <= shape->get_x() + shape->get_width() && 
		get_x() + get_width() >= shape->get_x() &&
		get_y() <= shape->get_y() + shape->get_height() &&
		get_y() + collision_height >= shape->get_y();
}

bool Models::Shape::check_polygon_collision(std::shared_ptr<Models::Shape> shape)
{
	int x = shape->get_x() + (shape->get_width() / 5);
	
	return get_x() - 1 <= x + shape->get_width() &&
		get_x() + get_width() + 1 >= x &&
		get_y() - 1 <= shape->get_y() + shape->get_height() &&
		get_y() + get_height() + 1 >= shape->get_y();
}

bool Models::Shape::check_triangle_collision(std::shared_ptr<Models::Shape> shape)
{
	double DEGREES_TO_RADIANS = (double)(M_PI / 180);

	int originx = _x + (_width / 2);
	int originy = _y + (_height);

	int x1 = _x;
	int y1 = _y;
	int x2 = _x + _width;
	int y2 = _y;
	int x3 = originx;
	int y3 = originy;

	// 1 translate to center
	x1 -= originx;
	y1 -= originy;
	x2 -= originx;
	y2 -= originy;

	// 2 rotate
	double radian = DEGREES_TO_RADIANS * (_angle * -1);

	float x1r = (cos(radian) * x1) - (sin(radian) * y1) + originx;
	float y1r = (sin(radian) * x1) + (cos(radian) * y1) + originy;
	float x2r = (cos(radian) * x2) - (sin(radian) * y2) + originx;
	float y2r = (sin(radian) * x2) + (cos(radian) * y2) + originy;

	int playerx = shape->get_x() + (shape->get_width() / 2);
	int playery = shape->get_y() + (shape->get_height() / 2);

	int beam_area = area(x1r, y1r, x2r, y2r, x3, y3);
	int a1 = area(playerx, playery, x2r, y2r, x3, y3);
	int a2 = area(x1r, y1r, playerx, playery, x3, y3);
	int a3 = area(x1r, y1r, x2r, y2r, playerx, playery);

	return (beam_area == a1 + a2 + a3);
}

float Models::Shape::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs(((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / 2.0);
}