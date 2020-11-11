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
#include "../Models/Color.h"

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

/**
* Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* Namespace for the facades
	*/
	namespace Facades {
		/**
		* Containing all methods and references to draw text with SDL_ttf
		*/
		class GRAPHICS_API TextFacade : public TextureFacade {
		private:
			/**
			* Text of the TextFacade
			*/
			std::string _text;

			/**
			* Color of the TextFacade
			*/
			SDL_Color _color;

			/**
			* Height of the TextFacade
			*/
			int _height;
		public:
			TextFacade(const std::string& path, const std::string& text, const Color& color, const int height);

			/**
			* Creates an SDL_Texture for a given path
			*/
			void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer);
		};
	}
}