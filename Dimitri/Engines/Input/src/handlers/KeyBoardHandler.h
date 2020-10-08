#pragma once
#include "../enums/EventEnum.cpp"
#include "../../../PhysicsCollision/src/Models/Shape.h"
#include "../../../Graphics/src/Models/Sprite.h"
#include "../interfaces/IInputHandler.h"
#include <string>

class __declspec(dllexport) KeyBoardHandler : public IInputHandler {
public:
	KeyBoardHandler();
	void handle_event(EventEnum num, Models::Sprite* sprite, Models::Shape shape);
};
