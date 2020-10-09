#include "TextureFacade.h"

Facades::TextureFacade::TextureFacade() : _texture(nullptr, SDL_DestroyTexture) {}

void Facades::TextureFacade::create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer, const std::string path)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		_texture.reset(SDL_CreateTextureFromSurface(renderer.get(), loadedSurface), SDL_DestroyTexture);

		if (_texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	loadedSurface = NULL;
}

std::shared_ptr<SDL_Texture> Facades::TextureFacade::get_texture()
{
	return _texture;
}