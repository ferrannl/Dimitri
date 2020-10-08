#include "Sprite.h"

//// move constructor
//Models::Sprite::Sprite(Models::Sprite&& sprite)
//	: _x{ sprite.get_x() }, _y{ sprite.get_y() }, _z{ sprite.get_z() }, _height{ sprite.get_height() }, _width{ sprite.get_width() }, _path{ sprite.get_path() }, _angle{ sprite.get_angle() }, _flipstatus{ sprite.get_flip_status() }
//{
//	_facade = sprite.get_texture_facade();
//
//	sprite._path = { nullptr };
//	sprite._facade = { nullptr };
//}
//
//Models::Sprite& Models::Sprite::operator=(Models::Sprite&& sprite)
//{
//	// check if other is not equal to this
//	if (this != &sprite) {
//
//		// steal resources
//		_x = sprite._x;
//		_y = sprite._y;
//		_z = sprite._z;
//		_width = sprite._width;
//		_height = sprite._height;
//		_angle = sprite._angle;
//		_path = sprite._path;
//		_facade = sprite._facade;
//		_flipstatus = sprite._flipstatus;
//
//		//reset other instance
//		sprite._path = { nullptr };
//		sprite._facade = { nullptr };
//	}
//
//	// to support chaining ie 1 = 2 = 3
//	return *this;
//}
//
//Models::Sprite::~Sprite()
//{
//	delete _path;
//	_facade = { nullptr };
//}


Models::Sprite::Sprite(const int x, const int y, const int z, const int height, const int width, const std::string path, const float angle, const Enums::FlipEnum flipstatus)
	: _x{ x }, _y{ y }, _z{ z }, _height{ height }, _width{ width }, _path{ path }, _angle{ angle }, _flipstatus{ flipstatus } {
	_facade = { nullptr };
}

const int Models::Sprite::get_converted_y(const int height)
{
	return height - (_y + _height);
}

const int Models::Sprite::get_x()
{
	return _x;
}

const int Models::Sprite::get_z()
{
	return _z;
}

const int Models::Sprite::get_y()
{
	return _y;
}

const int Models::Sprite::get_width()
{
	return _width;
}

const int Models::Sprite::get_height()
{
	return _height;
}

const float Models::Sprite::get_angle()
{
	return _angle;
}

std::shared_ptr<Facades::TextureFacade> Models::Sprite::get_texture_facade()
{
	return _facade;
}

Enums::FlipEnum Models::Sprite::get_flip_status()
{
	return _flipstatus;
}

const std::string Models::Sprite::get_path()
{
	return _path;
}

void Models::Sprite::set_x(const int x)
{
	_x = x;
}

void Models::Sprite::set_z(const int z)
{
	_z = z;
}

void Models::Sprite::set_y(const int y)
{
	_y = y;
}

void Models::Sprite::set_width(const int width)
{
	_width = width;
}

void Models::Sprite::set_height(const int height)
{
	_height = height;
}

void Models::Sprite::set_angle(const float angle)
{
	_angle = angle;
}

void Models::Sprite::set_flip_status(Enums::FlipEnum flipstatus)
{
	_flipstatus = flipstatus;
}

void Models::Sprite::set_facade(std::shared_ptr<Facades::TextureFacade> facade)
{
	_facade = facade;
}

void Models::Sprite::create_texture_facade()
{
	_facade = std::make_shared<Facades::TextureFacade>();
}