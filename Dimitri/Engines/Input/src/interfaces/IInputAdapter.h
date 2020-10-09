#pragma once
#include <SDL.h>
#include "../enums/EventEnum.cpp"

class __declspec(dllexport) IInputAdapter
{
public:
	virtual EventEnum translate_to_enum(const SDL_Event event)const = 0;
};