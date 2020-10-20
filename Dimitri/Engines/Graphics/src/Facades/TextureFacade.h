#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "../Exceptions/GraphicsExceptions.h"
#include <iostream>

namespace Facades {
	class TextureFacade {
	private:
		std::shared_ptr<SDL_Texture> _texture;

	public:
		TextureFacade();

		void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer, const std::string path);
		std::shared_ptr<SDL_Texture> get_texture();
	};
}