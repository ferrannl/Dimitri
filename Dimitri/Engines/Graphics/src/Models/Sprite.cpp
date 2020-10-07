#include "Sprite.h"


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

Facades::TextureFacade* Models::Sprite::get_texture_facade()
{
	return _facade;
}

const char* Models::Sprite::get_path()
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

void Models::Sprite::set_facade(Facades::TextureFacade* facade)
{
	_facade = facade;
}

void Models::Sprite::create_texture_facade()
{
	_facade = { new Facades::TextureFacade };
}
