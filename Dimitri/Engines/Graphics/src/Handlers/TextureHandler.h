#pragma once
#include "../Models/Sprite.h"
#include <SDL.h>
#include <stdio.h>
#include <string>

namespace Handlers 
{
	class TextureHandler 
	{
		public:
			void DrawSprite(Models::Sprite sprite);

			//Loads individual image as texture
			SDL_Texture* loadTexture(std::string path);

			//The window we'll be rendering to
			SDL_Window* gWindow = NULL;

			//The window renderer
			SDL_Renderer* gRenderer = NULL;

			//Current displayed texture
			SDL_Texture* gTexture = NULL;

			void CreateRenderer(SDL_Window* gWindow);

			bool loadMedia(std::string path);
	};
}