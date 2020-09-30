#pragma once
#include "../Models/Sprite.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>

namespace Facades
{
	class TextureFacade
	{
	private:
		SDL_Renderer* _renderer;
		void create_renderer(SDL_Window* window);
	public:
		TextureFacade(SDL_Window* window) {
			create_renderer(window);
		}

		SDL_Texture* create_texture(std::string path);

		bool load_sprite(Models::Sprite* sprite);

		void update_screen(SDL_Window* window, std::vector<Models::Sprite*> sprites);
	};
}