#include "Window.h"

const std::vector<Models::Sprite*> Models::Window::get_sprites()
{
	return _sprites;
}

Models::Window::Window(const char* title, const int x, const int y, const int height, const int width) : _x{ x }, _y{ y }, _height{ height }, _width{ width }, _title{ title } {
	_facade = new Facades::WindowFacade();
}

void Models::Window::create()
{
	_facade->create_window(_title, _x, _y, _height, _width);
	_facade->create_renderer();
}

void Models::Window::update()
{
	_facade->update_window(_sprites);
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

void Models::Window::set_sprites(std::vector<Models::Sprite*> sprites)
{
	_sprites = sprites;
	_facade->create_sprites(_sprites);
}