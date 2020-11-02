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

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

namespace Graphics {
	/**
	* Contains all the references needed for the SDL_Texture
	*/
	namespace Facades {
		class GRAPHICS_API SpriteFacade : public TextureFacade {
		public:
			SpriteFacade(const std::string path);

			/**
			* Creates an SDL_Texture for a given path
			*/
			void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer);
		};
	}
}