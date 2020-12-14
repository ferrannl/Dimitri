#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "../Exceptions/GraphicsExceptions.h"
#include <iostream>
#include "TextureFacade.h"
#include "../Models/Color.h"

struct SDL_Renderer;

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
		class TextFacade : public TextureFacade {
		private:
			/**
			* \brief The text of the TextFacade
			*/
			const std::string _text;

			/**
			* \brief The Color of the TextFacade
			*/
			const Graphics::Models::Color& _color;

			/**
			* \brief The height of the TextFacade
			*/
			const float _height;
		public:
			TextFacade(const std::string& path, const std::string& text, const Models::Color& color, const float height, int opacity);

			/**
			* \brief Creates a SDL_Texture
			*/
			void create_texture(std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>& renderer);
		};
	}
}