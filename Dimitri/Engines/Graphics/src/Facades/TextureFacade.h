#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL_image.h>
#include <memory>
#include<stdarg.h>
#include <iostream>
#include "../Exceptions/GraphicsExceptions.h"

struct SDL_Color;

namespace Graphics {
	namespace Facades {
		class __declspec(dllexport) TextureFacade {
		protected:
			std::string _path;
			std::shared_ptr<SDL_Texture> _texture;
		public:
			TextureFacade(const std::string path);
			virtual void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer) = 0;
			std::shared_ptr<SDL_Texture> get_texture();
		};
	}
}