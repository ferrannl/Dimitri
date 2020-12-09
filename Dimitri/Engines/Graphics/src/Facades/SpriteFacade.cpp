#include "SpriteFacade.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace Graphics;

Facades::SpriteFacade::SpriteFacade(const std::string& path) : TextureFacade(path) {}

void Facades::SpriteFacade::create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer)
{
	try {
		//Load image at specified path
		std::unique_ptr<SDL_Surface, void(*)(SDL_Surface*)> loadedSurface = { IMG_Load(_path.c_str()), SDL_FreeSurface };

		if (loadedSurface == NULL) {
			throw Exceptions::CannotLoadImage();
		}

		//Create texture from surface pixels
		_texture.reset(SDL_CreateTextureFromSurface(renderer.get(), loadedSurface.get()));

		if (_texture == NULL) {
			throw Exceptions::CannotCreateTexture();
		}
	}
	catch (Exceptions::CannotLoadImage& e) {
		std::cout << e.get() << ": " << _path << std::endl;
	}
	catch (Exceptions::CannotCreateTexture& e) {
		std::cout << e.get();
	}
}
