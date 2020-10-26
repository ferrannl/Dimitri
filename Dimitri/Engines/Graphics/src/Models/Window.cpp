#include "Window.h"
using namespace Graphics;

std::shared_ptr<Graphics::Models::Texture> Graphics::Models::Window::get_texture_by_path(const std::string& path) const
{
	for (std::shared_ptr<Models::Texture> t : _textures) {
		if (t->get_path() == path) {
			return t;
		}
	}
	return nullptr;
}

Models::Window::Window(const std::string title, const int height, const int width) : _title{ title }, _height{ height }, _width{ width } {
	_facade = std::make_unique<Facades::WindowFacade>();
}

int Models::Window::create()
{
	int retVal = NULL;

	retVal = _facade->create_window(_title, _height, _width);
	retVal = _facade->create_renderer();

	return retVal;
}

void Models::Window::update()
{
	_facade->update_window(_textures);
}

void Models::Window::destroy()
{
	_facade->destroy();
}

void Graphics::Models::Window::add_texture(const std::shared_ptr<Texture>& texture)
{
	_textures.push_back(texture);
	_facade->create_texture(texture, get_texture_by_path(texture->get_path()));
}

void Graphics::Models::Window::remove_texture(const std::shared_ptr<Texture>& texture)
{
	auto it = std::find(_textures.begin(), _textures.end(), texture);

	// If element was found 
	if (it != _textures.end()) {
		int index = std::distance(_textures.begin(), it);
		_textures.erase(_textures.begin() + index);
	}
}

std::vector<std::shared_ptr<Models::Texture>> Graphics::Models::Window::get_textures() const
{
	return _textures;
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