#pragma once
#include <tuple>
#include <SDL.h>
#include <SDL_mouse.h>

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else INPUT_API __declspec(import)
#endif
#else
#define INPUT_API
#endif

namespace Facades{
	class INPUT_API MouseFacade {
	public:
		std::tuple<int, int> get_mouse_position() const;
	};
}