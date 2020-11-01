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

namespace Graphics {
	namespace Facades {
    /**
		* Contains all the references needed for the SDL_Texture
		*/
		class GRAPHICS_API TextureFacade {
		protected:
      /**
			* Path to the texture
			*/
			std::string _path;
      /**
			* An instance of SDL_Texture
			*/
			std::shared_ptr<SDL_Texture> _texture;
		public:
			TextureFacade(const std::string path);
      
      /**
			* Creates an SDL_Texture for a given path
			*/
			virtual void create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer) = 0;
      
      /**
			* Returns the SDL_Texture
			*/
			std::shared_ptr<SDL_Texture> get_texture() const;
		};
	}
}