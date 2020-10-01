#include "Window.h"

const std::vector<Models::Sprite*> Models::Window::get_sprites()
{
	return _sprites;
}

void Models::Window::create()
{
	_facade->create(_title, _x, _y, _height, _width);
}

void Models::Window::update()
{
	_facade->update_sprites(_sprites);
}

void Models::Window::destroy()
{
	_facade->destroy();
}

const int Models::Window::get_x()
{
	return _x;
}

const int Models::Window::get_y()
{
	return _x;
}

const int Models::Window::get_height()
{
	return _height;
}

const int Models::Window::get_width()
{
	return _width;
}

const char* Models::Window::get_title()
{
	return _title;
}

void Models::Window::create_sprites()
{
	_facade->create_sprites(_sprites);
}

void Models::Window::set_sprites(std::vector<Models::Sprite*> sprites)
{
	_sprites = sprites;
}
