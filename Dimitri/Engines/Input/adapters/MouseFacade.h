#pragma once
#include <tuple>
#include <SDL.h>
class __declspec(dllexport) MouseFacade
{
public:
	MouseFacade();
	std::tuple<int, int> get_mouse_position() const;
};