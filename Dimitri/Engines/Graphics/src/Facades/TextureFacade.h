#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "../Exceptions/GraphicsExceptions.h"
#include <iostream>

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

typedef struct SDL_Texture SDL_Texture;
typedef struct SDL_Renderer SDL_Renderer;

namespace Graphics {
	namespace Facades {
		class GRAPHICS_API TextureFacade {
		private:
			std::shared_ptr<SDL_Texture> _texture;

		public:
			TextureFacade();

			void create_texture(std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>& renderer, const std::string path);
			std::shared_ptr<SDL_Texture> get_texture();
		};
	}
}
