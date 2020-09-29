#include "TextureHandler.h"
#include <SDL_image.h>

void Handlers::TextureHandler::DrawSprite(Models::Sprite sprite)
{

}

SDL_Texture* Handlers::TextureHandler::loadTexture(std::string path)
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
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Handlers::TextureHandler::CreateRenderer(SDL_Window* gWindow)
{
	//Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
}

bool Handlers::TextureHandler::loadMedia(std::string path)
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	gTexture = loadTexture(path);
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	return success;
}

void Handlers::TextureHandler::UpdateScreen(SDL_Window* window, SDL_Texture* texture, SDL_Renderer* renderer)
{
	//Clear screen
	SDL_RenderClear(renderer);

	//Render texture to screen
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	//Update screen
	SDL_RenderPresent(renderer);
}
