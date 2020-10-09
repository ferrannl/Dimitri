#pragma once
#include <tuple>
#include "../enums/EventEnum.cpp"
#include "../interfaces/IInputAdapter.h"

class __declspec(dllexport) MouseAdapter : public IInputAdapter {
public:
	MouseAdapter();
	EventEnum translate_to_enum(const SDL_Event event) const;
};
