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
* \namespace Graphics
* \brief Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* \namespace Graphics::Facades
	* \brief Namespace for the facades in the graphics engine
	*/
	namespace Facades {
		/**
		* \class TextFacade
		* \brief Class contains the methods to draw text with SDL_ttf
		*/
		class GRAPHICS_API TextFacade : public TextureFacade {
		private:
			/**
			* \brief The text of the TextFacade
			*/
			std::string _text;

			/**
			* \brief The Color of the TextFacade
			*/
			SDL_Color _color;

			/**
			* \brief The height of the TextFacade
			*/
			float _height;
		public:
			TextFacade(const std::string& path, const std::string& text, const Models::Color& color, const float height);

			/**
			* \brief Creates a SDL_Texture
			*/
			void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer);
		};
	}
}