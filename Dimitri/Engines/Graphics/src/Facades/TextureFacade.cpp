#include "TextureFacade.h"
#include <SDL_image.h>


void Facades::TextureFacade::create_renderer(SDL_Window* window)
{
	//Create renderer for window
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	}
}

bool Facades::TextureFacade::load_sprite(Models::Sprite* sprite)
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	SDL_Texture* texture = create_texture(sprite->get_path());
	if (texture == NULL)
	{
		delete texture;
		printf("Failed to load texture image!\n");
		success = false;
	}
	else {
		sprite->add_texture(texture);
	}

	return success;
}

SDL_Texture* Facades::TextureFacade::create_texture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Facades::TextureFacade::update_screen(SDL_Window* window, std::vector<Models::Sprite*> sprites)
{
	//Clear screen
	SDL_RenderClear(_renderer);

	for (Models::Sprite* sprite : sprites) {
		SDL_Rect rect;
		
		rect.x = sprite->get_x();
		rect.y = sprite->get_y();
		rect.w = sprite->get_width();
		rect.h = sprite->get_height();

		//Render texture to screen
		SDL_RenderCopy(_renderer, sprite->get_texture(), NULL, &rect);
	}

	//Update screen
	SDL_RenderPresent(_renderer);
}
