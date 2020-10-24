#pragma once
#include "../Enums/FlipEnum.h"
#include <SDL.h>

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else GRAPHICS_API __declspec(import)
#endif
#else
#define GRAPHICS_API
#endif

namespace Adapters {
	class FlipEnumAdapter {
	public:
		SDL_RendererFlip get_sdl_flip(const Enums::FlipEnum flipstatus);
	};
}