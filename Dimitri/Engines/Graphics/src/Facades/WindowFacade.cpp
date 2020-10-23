#include "WindowFacade.h"

int Facades::WindowFacade::create_window(const std::string title, const int height, const int width)
{
	try {
		if (SDL_Init(SDL_INIT_VIDEO) < NULL) {
			throw Exceptions::SDLInitFailed();
		}

		_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));

		if (_window == NULL) {
			throw Exceptions::CannotCreateWindow();
		}

		return 1;
	}
	catch (Exceptions::SDLInitFailed& e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
	catch (Exceptions::CannotCreateWindow& e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
}

void Facades::WindowFacade::create_sprites(std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites)
{
	if (!_renderer) {
		std::cout << "Create a renderer first" << std::endl;
		return;
	}


	for (std::unique_ptr<Models::Sprite>& sprite : *sprites) {
		// check if the texuture already exists
		std::shared_ptr<Facades::TextureFacade> facade = get_if_exists(sprites, sprite->get_path());

		if (facade) {
			sprite->set_facade(facade);
		}
		else {
			sprite->create_texture_facade();
			sprite->get_texture_facade()->create_texture(_renderer, sprite->get_path());
		}
	}
}

void Facades::WindowFacade::update_window(std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites)
{
	//Clear screen
	SDL_RenderClear(_renderer.get());

	int depth = 0;
	int objectcounter = 0;

	while (objectcounter < sprites->size()) {
		for (std::unique_ptr<Models::Sprite>& sprite : *sprites) {
			if (sprite->get_z() == depth) {
				SDL_Rect rect;

				rect.x = sprite->get_x();
				rect.y = sprite->get_converted_y(SDL_GetWindowSurface(_window.get())->h);
				rect.w = sprite->get_width();
				rect.h = sprite->get_height();

				//Render texture to screen
				try {
					SDL_Point center = { 0,0 };
					int retVal = SDL_RenderCopyEx(_renderer.get(), sprite->get_texture_facade()->get_texture().get(), NULL, &rect, sprite->get_angle(), &center, _flip_enum_adapter.get_sdl_flip(sprite->get_flip_status()));
					
					if (retVal < NULL) {
						throw Exceptions::CannotRenderSpriteTexture();
					}
				}
				catch (Exceptions::CannotRenderSpriteTexture& e) {
					std::cout << e.get() << std::endl;
				}
				
				objectcounter++;
			}
		}
		depth++;
	}

	//Update screen
	SDL_RenderPresent(_renderer.get());
}

std::shared_ptr<Facades::TextureFacade> Facades::WindowFacade::get_if_exists(std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites, const std::string path)
{
	for (std::unique_ptr<Models::Sprite>& sprite : *sprites) {
		if (sprite->get_path() == path) {
			return sprite->get_texture_facade();
		}
	}

	return nullptr;
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

	//Quit SDL subsystems
	SDL_Quit();
}