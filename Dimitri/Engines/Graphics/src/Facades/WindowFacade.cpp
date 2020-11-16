#include "WindowFacade.h"
#include <map>
#include <SDL_ttf.h>
using namespace Graphics;

int Facades::WindowFacade::create_window(const std::string& title, const int height, const int width)
{
	_window_height = height;
	_window_width = width;
	set_level_size(height, width);
	try {
		if (SDL_Init(SDL_INIT_VIDEO) < NULL) {
			throw Exceptions::SDLInitFailed();
		}

		//Initialize SDL_ttf
		if (TTF_Init() == -1)
		{
			throw Exceptions::TTFInitFailed();
		}

		_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));

		if (_window == NULL) {
			throw Exceptions::CannotCreateWindow();
		}
		_fps = std::make_unique<Utility::Time::Fps>();
		return 1;
	}
	catch (Exceptions::SDLInitFailed& e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
	catch (Exceptions::TTFInitFailed& e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
	catch (Exceptions::CannotCreateWindow& e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
}

void Graphics::Facades::WindowFacade::create_texture(const std::shared_ptr<Models::Texture>& texture, const std::shared_ptr<Models::Texture>& matching_texture)
{
	if (!_renderer) {
		std::cout << "Create a renderer first" << std::endl;
		return;
	}

	std::shared_ptr<Facades::TextureFacade> facade = matching_texture != nullptr ? matching_texture->get_texture_facade() : nullptr;

	// check if the texture already exists
	if (facade) {
		texture->set_facade(facade);
	}
	else {
		texture->create_texture_facade();
		texture->get_texture_facade()->create_texture(_renderer);
	}

}

void Facades::WindowFacade::update_window(std::vector<std::shared_ptr<Models::Texture>> textures)
{
	//Clear screen
	SDL_RenderClear(_renderer.get());
	std::map<int, std::vector<std::shared_ptr<Models::Texture>>> ordered_textures{};
	for (std::shared_ptr<Models::Texture>& texture : textures) {
		if (texture.get()->is_visible()) {
			ordered_textures[texture.get()->get_z()].push_back(texture);
		}
	}

	for (const std::pair<int, std::vector<std::shared_ptr<Graphics::Models::Texture>>>& kv : ordered_textures) {
		for (const std::shared_ptr<Graphics::Models::Texture>& texture : kv.second) {
			SDL_Rect rect;

			rect.x = texture->get_x() - _camera_x;
			rect.y = texture->get_converted_y(_level_height) - _camera_y;
			rect.w = texture->get_width();
			rect.h = texture->get_height();

			//Render texture to screen
			try {
				SDL_Point center = { 0,0 };
				int retVal = SDL_RenderCopyEx(_renderer.get(), texture->get_texture_facade()->get_texture(), NULL, &rect, texture->get_angle(), &center, _flip_enum_adapter.get_sdl_flip(texture->get_flip_status()));

				if (retVal < NULL) {
					throw Exceptions::CannotRenderSpriteTexture();
				}
			}
			catch (Exceptions::CannotRenderSpriteTexture& e) {
				std::cout << e.get() << std::endl;
			}
		}
	}

	//Update screen
	SDL_RenderPresent(_renderer.get());

	_fps.get()->update();
}

int Graphics::Facades::WindowFacade::get_fps()
{
	return _fps.get()->get();
}

void Graphics::Facades::WindowFacade::set_camera_pos(const int x, const int y)
{
	if (x + _window_width < _level_width && x >= 0) {
		_camera_x = x;
	}
	else if (x + _window_width > _level_width) {
		_camera_x = _level_width - _window_width;
	}
	else if (x < 0) {
		_camera_x = 0;
	}

	if (y + _window_height < _level_height && y >= 0) {
		_camera_y = y;
	}
	else if (y + _window_height > _level_height) {
		_camera_y = _level_height - _window_height;
	}
	else if (y < 0) {
		_camera_y = 0;
	}

}

std::tuple<int, int> Graphics::Facades::WindowFacade::get_camera_pos() const
{
	return std::make_tuple(_camera_x, _camera_y);
}

void Graphics::Facades::WindowFacade::set_level_size(const int height, const int width)
{
	_level_height = height;
	_level_width = width;

	_camera_x = 0;
	_camera_y = _level_height - _window_height;
}

std::tuple<int, int> Graphics::Facades::WindowFacade::get_level_size() const
{
	return std::make_tuple(_level_width, _level_height);
}

void Graphics::Facades::WindowFacade::set_camera_pos(const int x, const int y)
{
	if (x + _window_width < _level_width && x >= 0) {
		_camera_x = x;
	}
	else if (x + _window_width > _level_width) {
		_camera_x = _level_width - _window_width;
	}
	else if (x < 0) {
		_camera_x = 0;
	}

	if (y + _window_height < _level_height && y >= 0) {
		_camera_y = y;
	}
	else if (y + _window_height > _level_height) {
		_camera_y = _level_height - _window_height;
	}
	else if (y < 0) {
		_camera_y = 0;
	}

}

void Graphics::Facades::WindowFacade::set_level_size(const int height, const int width)
{
	_level_height = height;
	_level_width = width;

	_camera_x = 0;
	_camera_y = _level_height - _window_height;
}

Facades::WindowFacade::WindowFacade() : _window(nullptr, SDL_DestroyWindow), _renderer(nullptr, SDL_DestroyRenderer), _flip_enum_adapter{} {}

int Facades::WindowFacade::create_renderer()
{
	try {
		_renderer.reset(SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED));

		if (_renderer == NULL)
		{
			throw Exceptions::CannotCreateRenderer();
		}

		SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);

		return 1;
	}
	catch (Exceptions::CannotCreateRenderer e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
}

void Facades::WindowFacade::destroy()
{
	// we might want to deallocate surfaces in the future
	//Destroy window
	SDL_DestroyWindow(_window.get());
	_window = NULL;
	TTF_Quit();
	//Quit SDL subsystems
	SDL_Quit();
}