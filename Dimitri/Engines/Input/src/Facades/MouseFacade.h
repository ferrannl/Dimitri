#pragma once
#include <tuple>
#include <SDL_mouse.h>

namespace Facades{
	class __declspec(dllexport) MouseFacade {
	public:
		std::tuple<int, int> get_mouse_position() const;
	};
}