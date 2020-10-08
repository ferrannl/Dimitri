#include "WindowFacade.h"

bool Facades::WindowFacade::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		return true;
	}
}

void Facades::WindowFacade::create_window(const char* title, const int xpos, const int ypos, const int height, const int width)
{
	//Start up SDL and create window
	if (!Facades::WindowFacade::Init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	}
}

void Facades::WindowFacade::create_sprites(std::vector<Models::Sprite*> sprites)
{
	if (!_renderer) {
		std::cout << "Create a renderer first" << std::endl;
		return;
	}

	for (Models::Sprite* sprite : sprites) {
		Facades::TextureFacade* facade = get_if_exists(sprites, sprite->get_path());

		if (facade) {
			sprite->set_facade(facade);
		}
		else {
			sprite->create_texture_facade();
			sprite->get_texture_facade()->create_texture(_renderer, sprite->get_path());
		}
	}
}

void Facades::WindowFacade::update_window(std::vector<Models::Sprite*> sprites)
{
	//Clear screen
	SDL_RenderClear(_renderer);

	int depth = 0;
	int objectcounter = 0;

	while (objectcounter < sprites.size()) {
		for (Models::Sprite* sprite : sprites) {
			if (sprite->get_z() == depth) {
				SDL_Rect rect;

				rect.x = sprite->get_x();
				rect.y = sprite->get_converted_y(SDL_GetWindowSurface(_window)->h);
				rect.w = sprite->get_width();
				rect.h = sprite->get_height();

				//Render texture to screen
				if (sprite->get_texture_facade()->get_texture()) {
					SDL_Point center = { 0,0 };
					SDL_RenderCopyEx(_renderer, sprite->get_texture_facade()->get_texture(), NULL, &rect, sprite->get_angle(), &center, get_sdl_flip(sprite->get_flip_status()));
				}
				objectcounter++;
			}
		}
		depth++;
	}

	//Update screen
	SDL_RenderPresent(_renderer);
}

Facades::TextureFacade* Facades::WindowFacade::get_if_exists(std::vector<Models::Sprite*> sprites, const char* path)
{
	for (Models::Sprite* sprite : sprites) {
		if (sprite->get_path() == path) {
			return sprite->get_texture_facade();
		}
	}

	return nullptr;
}

SDL_RendererFlip Facades::WindowFacade::get_sdl_flip(Enums::FlipEnum flipstatus)
{
	switch (flipstatus) {
	case Enums::FlipEnum::HORIZONTAL:
		return SDL_FLIP_HORIZONTAL;
	case Enums::FlipEnum::VERTICAL:
		return SDL_FLIP_VERTICAL;
	default:
		return SDL_FLIP_NONE;
	}
}

void Facades::WindowFacade::create_renderer()
{
	//Create renderer for window
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	}
}

void Facades::WindowFacade::destroy()
{
	// we might want to deallocate surfaces in the future
	//Destroy window
	SDL_DestroyWindow(_window);
	_window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
