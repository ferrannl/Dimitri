#include "Window.h"
using namespace Graphics;

Models::Window::Window(const std::string& title, int height, int width) : _title{ title }, _height{ height }, _width{ width } {
	_facade = std::make_unique<Facades::WindowFacade>();
}

std::mutex& Graphics::Models::Window::get_mutex()
{
	return _mutex;
}

std::shared_ptr<Models::Texture> Models::Window::get_matching_texture(const std::shared_ptr<Models::Texture>& texture) const
{
	for (std::shared_ptr<Models::Texture> t : _textures) {
		if (t->matches(texture)) {
			return t;
		}
	}
	return nullptr;
}

int Models::Window::create() const
{
	int retVal = NULL;

	retVal = _facade->create_window(_title, _height, _width);
	retVal = _facade->create_renderer();

	return retVal;
}

void Models::Window::update() const
{
	_facade->update_window(_textures);
}

void Models::Window::destroy() const
{
	_facade->destroy();
}

void Graphics::Models::Window::add_texture(const std::shared_ptr<Texture>& texture)
{
	_facade->create_texture(texture, get_matching_texture(texture));
	_textures.push_back(texture);
}

void Graphics::Models::Window::remove_texture(const std::shared_ptr<Texture>& texture)
{
	std::vector<std::shared_ptr<Texture>>::iterator it = std::find(_textures.begin(), _textures.end(), texture);

	// If element was found 
	if (it != _textures.end()) {
		int index = std::distance(_textures.begin(), it);
		_textures.erase(_textures.begin() + index);
	}
}

void Graphics::Models::Window::clear_textures()
{
	_textures.clear();
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

int Graphics::Models::Window::get_fps() const
{
	return _facade->get_fps();
}

int Graphics::Models::Window::get_ticks() const
{
	return _facade->get_ticks();
}

void Graphics::Models::Window::set_camera_pos(float x, float y)
{
	_facade->set_camera_pos(x,y);
}

std::tuple<int, int> Graphics::Models::Window::get_camera_pos() const
{
	return _facade->get_camera_pos();
}

void Graphics::Models::Window::set_scene_size(int height, int width)
{
	_facade->set_scene_size(height, width);
}

std::tuple<int, int> Graphics::Models::Window::get_scene_size() const
{
	return _facade->get_scene_size();
}

std::shared_ptr<Utility::Time::Timer> Graphics::Models::Window::get_timer() const
{
	return _facade->get_timer();
}
