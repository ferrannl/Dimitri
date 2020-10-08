#pragma once
#include "../Enums/FlipEnum.h"
#include <SDL.h>

namespace Adapters {
	class __declspec(dllexport) FlipEnumAdapter {
	public:
		SDL_RendererFlip get_sdl_flip(Enums::FlipEnum flipstatus);
	};
}