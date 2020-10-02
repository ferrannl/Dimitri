#pragma once
#include "../Models/Sprite.h"
#include "../Models/Texture.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL_image.h>

namespace Facades
{
	class __declspec(dllexport) TextureFacade
	{
	private:
		SDL_Renderer* _renderer;
		std::vector<Models::Texture*> _textures;
		void create_renderer(SDL_Window* window);

		Models::Texture* get_if_exists(const char* path);
		Models::Texture* create_texture_model(const char* path, SDL_Texture* texture);
	public:
		TextureFacade(SDL_Window* window) {
			create_renderer(window);
			_textures = {};
		}

		SDL_Texture* create_texture(std::string path);
		bool load_sprite(Models::Sprite* sprite);
		void update_screen(SDL_Window* window, std::vector<Models::Sprite*> sprites);
	};
}