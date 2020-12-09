#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "../Exceptions/GraphicsExceptions.h"
#include <iostream>
#include "TextureFacade.h"

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
		* \class SpriteFacade
		* \brief Class contains the methods to draw sprites with SDL
		*/
		class SpriteFacade : public TextureFacade {
		public:
			SpriteFacade(const std::string& path);

			/**
			* \brief Creates a SDL_Texture
			*/
			void create_texture(std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>& renderer);
		};
	}
}