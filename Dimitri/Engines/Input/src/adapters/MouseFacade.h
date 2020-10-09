#pragma once
#include <tuple>
#include <SDL.h>

class MouseFacade
{
public:
	std::tuple<int, int> get_mouse_position() const;
};