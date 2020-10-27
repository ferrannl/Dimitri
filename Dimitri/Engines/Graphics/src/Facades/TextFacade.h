#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL_image.h>
#include <memory>
#include "../Exceptions/GraphicsExceptions.h"
#include <iostream>
#include "TextureFacade.h"

namespace Graphics {
	namespace Facades {
		class __declspec(dllexport) TextFacade : public TextureFacade {
		private:
			std::string _text;
			SDL_Color _color;
			int _height;
		public:
			TextFacade(const std::string path, const std::string text, const uint8_t color_red, uint8_t color_green, const uint8_t color_blue, const int height);
			void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer);
		};
	}
}