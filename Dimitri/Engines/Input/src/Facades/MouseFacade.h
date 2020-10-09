#pragma once
#include <tuple>
#include <SDL.h>
namespace Facades{
	class __declspec(dllexport) MouseFacade {
	public:
		std::tuple<int, int> get_mouse_position() const;
	};
}