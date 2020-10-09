#pragma once
#include <tuple>
#include <SDL.h>
#include "../enums/EventEnum.cpp"
#include "../interfaces/IInputAdapter.h"


class __declspec(dllexport) MouseAdapter : public IInputAdapter {
public:
	MouseAdapter();
	std::tuple<int, int> get_mouse_position() const;
	EventEnum translate_to_enum(const SDL_Event event) const;
};
