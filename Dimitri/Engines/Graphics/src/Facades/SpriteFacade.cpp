#include "SpriteFacade.h"
using namespace Graphics;

Facades::SpriteFacade::SpriteFacade(const std::string& path, int opacity) : TextureFacade(path, opacity) {}

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
		SDL_Texture* t = SDL_CreateTextureFromSurface(renderer.get(), loadedSurface);
		SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(t, _opacity);
		_texture.reset(t);

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
