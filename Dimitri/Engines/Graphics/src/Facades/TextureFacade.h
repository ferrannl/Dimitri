#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include<stdarg.h>
#include <iostream>"
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
		using TextureDestroyer = void (*)(SDL_Texture*);
		/**
		* \class TextureFacade
		* \brief Class contains the references to the SDL_Texture
		*/
		class GRAPHICS_API TextureFacade {
		protected:
			/**
			* \brief Path to the Texture
			*/
			std::string _path;

			/**
			* \brief An instance of SDL_Texture
			*/
			std::unique_ptr<SDL_Texture, TextureDestroyer> _texture;

			/**
			* \brief The opacity of the Texture
			* 0 is transparent, 255 is opaque
			*/
			uint8_t _opacity;
		public:
			TextureFacade(const std::string& path, int opacity);

			/**
			* \brief Creates a SDL_Texture
			*/
			virtual void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer) = 0;

			/**
			* \brief Returns the SDL_Texture
			*/
			SDL_Texture* get_texture() const;
		};
	}
}