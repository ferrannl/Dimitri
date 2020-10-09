#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL_image.h>

namespace Facades {
	class __declspec(dllexport) TextureFacade {
	private:
		SDL_Texture* _texture;

	public:
		TextureFacade() {
			_texture = { nullptr };
		}

		void create_texture(SDL_Renderer* renderer, const char* path);
		SDL_Texture* get_texture();
	};
}