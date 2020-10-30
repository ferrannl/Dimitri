#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "../Exceptions/GraphicsExceptions.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

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
	* Namespace for all the facades in the project
	*/
	namespace Facades {
		/**
		* Contains all the references needed for the SDL_Texture
		*/
		class GRAPHICS_API TextureFacade {
		private:
			/**
			* An instance of SDL_Texture
			*/
			std::shared_ptr<SDL_Texture> _texture;

		public:
			TextureFacade();

			/**
			* Creates an SDL_Texture for a given path
			*/
			void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer, const std::string path);

			/**
			* Returns the SDL_Texture
			*/
			std::shared_ptr<SDL_Texture> get_texture();
		};
	}
}