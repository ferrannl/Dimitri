#include "Window.h"

const std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> Models::Window::get_sprites()
{
	return _sprites;
}

Models::Window::Window(const std::string title, const int height, const int width) : _title{ title }, _height { height }, _width{ width } {
	_facade = std::make_unique<Facades::WindowFacade>();
}

void Models::Window::create()
{
	_facade->create_window(_title, _height, _width);
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

const int Models::Window::get_height()
{
	return _height;
}

const int Models::Window::get_width()
{
	return _width;
}

const std::string Models::Window::get_title()
{
	return _title;
}

void Models::Window::set_sprites(std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites)
{
	_sprites = sprites;
	_facade->create_sprites(_sprites);
}