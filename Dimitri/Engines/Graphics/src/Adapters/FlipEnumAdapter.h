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

namespace Adapters {
	class GRAPHICS_API FlipEnumAdapter {
	public:
		SDL_RendererFlip get_sdl_flip(const Enums::FlipEnum flipstatus);
	};
}