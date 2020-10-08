#pragma once
#include <SDL.h>
#include "../enums/EventEnum.cpp"
#include <string>
#include <vector>
#include "../../../PhysicsCollision/src/Models/Shape.h"
#include "../../../Graphics/src/Models/Sprite.h"
#include "../handlers/KeyBoardHandler.h"
#include <tuple>
#include "../handlers/MouseHandler.h"
class __declspec(dllexport) EventFacade
{
private:
	IInputHandler* _handler;
public:
	EventFacade();
	EventEnum translateToEnum(SDL_Event event);
	void handle_input(SDL_Event event, Models::Sprite* sprite, Models::Shape shape);
};