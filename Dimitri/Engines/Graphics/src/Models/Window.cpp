#include "Window.h"

std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> Models::Window::get_sprites() const
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

int Models::Window::get_height() const
{
	return _height;
}

int Models::Window::get_width() const
{
	return _width;
}

const std::string Models::Window::get_title() const
{
	return _title;
}

void Models::Window::set_sprites(const std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites)
{
	_sprites = sprites;
	_facade->create_sprites(_sprites);
}