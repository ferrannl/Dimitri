#pragma once
#include <SDL.h>
#include "../enums/EventEnum.cpp"
#include "../interfaces/IInputAdapter.h"

class __declspec(dllexport) KeyBoardAdapter : public IInputAdapter {
public:
	KeyBoardAdapter();
	EventEnum translate_to_enum(const SDL_Event event)const;
};
