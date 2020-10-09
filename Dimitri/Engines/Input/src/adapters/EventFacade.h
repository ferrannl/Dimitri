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
#include "../interfaces/IInputAdapter.h"
#include "KeyBoardAdapter.h"

class __declspec(dllexport) EventFacade {
private:
	std::shared_ptr<IInputHandler> _handler;
	std::shared_ptr<IInputAdapter> _adapter;

public:
	EventFacade();
	EventEnum translate_to_enum(const SDL_Event event);
	void handle_input(const SDL_Event event , Models::Sprite* sprite, Models::Shape shape);
};
