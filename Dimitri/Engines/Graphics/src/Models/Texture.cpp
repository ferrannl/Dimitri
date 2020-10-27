#include "Texture.h"
using namespace Graphics;

Models::Texture::Texture(const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path) :
	_x{ x }, _y{ y }, _z{ z }, _height{ height }, _width{ width }, _angle{ angle }, _path{ path }, _facade{ nullptr }, _flipstatus{ Enums::FlipEnum::NONE } {}

int Models::Texture::get_converted_y(int height) const
{
	return height - (_y + _height);
}

int Models::Texture::get_x() const
{
	return _x;
}

int Models::Texture::get_z() const
{
	return _z;
}

int Models::Texture::get_y() const
{
	return _y;
}

int Models::Texture::get_width() const
{
	return _width;
}

int Models::Texture::get_height() const
{
	return _height;
}

float Models::Texture::get_angle() const
{
	return _angle;
}

std::string Models::Texture::get_path() const
{
	return _path;
}

Enums::FlipEnum Models::Texture::get_flip_status() const
{
	return _flipstatus;
}

std::shared_ptr<Facades::TextureFacade> Models::Texture::get_texture_facade() const
{
	return _facade;
}

void Models::Texture::set_x(const int x)
{
	_x = x;
}

void Models::Texture::set_z(const int z)
{
	_z = z;
}

void Models::Texture::set_y(const int y)
{
	_y = y;
}

void Models::Texture::set_width(const int width)
{
	_width = width;
}

void Models::Texture::set_height(const int height)
{
	_height = height;
}

void Models::Texture::set_angle(const float angle)
{
	_angle = angle;
}

void Models::Texture::set_flip_status(const Enums::FlipEnum flipstatus)
{
	_flipstatus = flipstatus;
}

void Models::Texture::set_facade(const std::shared_ptr<Facades::TextureFacade>& facade)
{
	_facade = facade;
}
