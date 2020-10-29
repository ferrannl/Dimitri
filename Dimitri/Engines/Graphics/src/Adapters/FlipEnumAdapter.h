#pragma once
#include "../Enums/FlipEnum.h"
#include <SDL.h>

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

//typedef struct SDL_Renderer SDL_Renderer;
//typedef struct SDL_RendererFlip SDL_RendererFlip;


namespace Graphics {
	namespace Adapters {
		class GRAPHICS_API FlipEnumAdapter {
		public:
			SDL_RendererFlip get_sdl_flip(const Enums::FlipEnum flipstatus);
		};
	}
}