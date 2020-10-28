#include "TextureFacade.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace Graphics;

Facades::TextureFacade::TextureFacade() : _texture(nullptr, SDL_DestroyTexture) {}

void Facades::TextureFacade::create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer, const std::string path)
{
	try {
		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());

		if (loadedSurface == NULL) {
			SDL_FreeSurface(loadedSurface);
			throw Exceptions::CannotLoadImage();
		}

		//Create texture from surface pixels
		_texture.reset(SDL_CreateTextureFromSurface(renderer.get(), loadedSurface), SDL_DestroyTexture);

		if (_texture == NULL) {
			throw Exceptions::CannotCreateTexture();
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	catch (Exceptions::CannotLoadImage& e) {
		std::cout << e.get() << ": " << path << std::endl;
	}
	catch (Exceptions::CannotCreateTexture& e) {
		std::cout << e.get();
	}
}

std::shared_ptr<SDL_Texture> Facades::TextureFacade::get_texture()
{
	return _texture;
}