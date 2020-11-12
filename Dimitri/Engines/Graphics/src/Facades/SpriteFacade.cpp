#include "SpriteFacade.h"
using namespace Graphics;

Facades::SpriteFacade::SpriteFacade(const std::string& path) : TextureFacade(path) {}

void Facades::SpriteFacade::create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer)
{
	try {
		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(_path.c_str());

		if (loadedSurface == NULL) {
			SDL_FreeSurface(loadedSurface);
			throw Exceptions::CannotLoadImage();
		}

		//Create texture from surface pixels
		_texture.reset(SDL_CreateTextureFromSurface(renderer.get(), loadedSurface));

		if (_texture == NULL) {
			throw Exceptions::CannotCreateTexture();
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	catch (Exceptions::CannotLoadImage& e) {
		std::cout << e.get() << ": " << _path << std::endl;
	}
	catch (Exceptions::CannotCreateTexture& e) {
		std::cout << e.get();
	}
}
