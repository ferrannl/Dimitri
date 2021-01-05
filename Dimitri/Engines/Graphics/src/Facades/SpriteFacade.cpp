#include "SpriteFacade.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace Graphics;

Facades::SpriteFacade::SpriteFacade(const std::string& path, int opacity) : TextureFacade(path, opacity) {}

void Facades::SpriteFacade::create_texture(std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>& renderer)
{
	try {
		//Load image at specified path
		std::unique_ptr<SDL_Surface, void(*)(SDL_Surface*)> loadedSurface = { IMG_Load(_path.c_str()), SDL_FreeSurface };

		if (loadedSurface == NULL) {
			throw Exceptions::CannotLoadImage();
		}
		
		//Create texture from surface pixels
		SDL_Texture* t = SDL_CreateTextureFromSurface(renderer.get(), loadedSurface.get());
		SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(t, _opacity);
		_texture.reset(t);

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
