#include "Sprite.h"
using namespace Graphics;

Models::Sprite::Sprite(const float x, const float y, const float z, const float height, const float width, const std::string path, const float angle, const Enums::FlipEnum flipstatus)
	: _x{ x }, _y{ y }, _z{ z }, _height{ height }, _width{ width }, _path{ path }, _angle{ angle }, _flipstatus{ flipstatus }, _facade{ nullptr } {}

float Models::Sprite::get_converted_y(const float height) const
{
	return height - (_y + _height);
}

float Models::Sprite::get_x() const
{
	return _x;
}

float Models::Sprite::get_z() const
{
	return _z;
}

float Models::Sprite::get_y() const
{
	return _y;
}

float Models::Sprite::get_width() const
{
	return _width;
}

float Models::Sprite::get_height() const
{
	return _height;
}

float Models::Sprite::get_angle() const 
{
	return _angle;
}

std::shared_ptr<Facades::TextureFacade> Models::Sprite::get_texture_facade() const
{
	return _facade;
}

Enums::FlipEnum Models::Sprite::get_flip_status() const
{
	return _flipstatus;
}

const std::string Models::Sprite::get_path() const
{
	return _path;
}

void Models::Sprite::set_x(const float x)
{
	_x = x;
}

void Models::Sprite::set_z(const float z)
{
	_z = z;
}

void Models::Sprite::set_y(const float y)
{
	_y = y;
}

void Models::Sprite::set_width(const float width)
{
	_width = width;
}

void Models::Sprite::set_height(const float height)
{
	_height = height;
}

void Models::Sprite::set_angle(const float angle)
{
	_angle = angle;
}

void Models::Sprite::set_flip_status(const Enums::FlipEnum flipstatus)
{
	_flipstatus = flipstatus;
}

void Models::Sprite::set_facade(const std::shared_ptr<Facades::TextureFacade> facade)
{
	_facade = facade;
}

void Models::Sprite::create_texture_facade()
{
	_facade = std::make_shared<Facades::TextureFacade>();
}