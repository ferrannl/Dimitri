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
		std::shared_ptr<SDL_Texture> _texture;

	public:
		TextureFacade();

		// copy
		TextureFacade(const Facades::TextureFacade& facade);
		TextureFacade& operator=(const Facades::TextureFacade& facade);

		// move
		TextureFacade(Facades::TextureFacade&& facade);
		TextureFacade& operator=(Facades::TextureFacade&& facade);

		void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer, const std::string path);
		std::shared_ptr<SDL_Texture> get_texture();

		~TextureFacade();
	};
}