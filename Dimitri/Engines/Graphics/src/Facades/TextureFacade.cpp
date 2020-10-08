#include "TextureFacade.h"

void Facades::TextureFacade::create_texture(SDL_Renderer* renderer, const char* path)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (_texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	loadedSurface = NULL;
}

SDL_Texture* Facades::TextureFacade::get_texture()
{
	return _texture;
}