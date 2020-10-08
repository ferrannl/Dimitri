#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL_image.h>
#include <memory>

namespace Facades {
	class __declspec(dllexport) TextureFacade {
	private:
		SDL_Texture* _texture;

	public:
		TextureFacade();

		// copy
		TextureFacade(const Facades::TextureFacade& facade);
		TextureFacade& operator=(const Facades::TextureFacade& facade);

		// move
		TextureFacade(Facades::TextureFacade&& facade);
		TextureFacade& operator=(Facades::TextureFacade&& facade);

		void create_texture(SDL_Renderer* renderer, const char* path);
		SDL_Texture* get_texture();

		~TextureFacade();
	};
}