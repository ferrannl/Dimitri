#pragma once
#include <SDL.h>
#include "../enums/KeyEnum.cpp"
#include <string>
#include <vector>
#include "../../../PhysicsCollision/src/Models/Shape.h"
#include "../../../Graphics/src/Models/Sprite.h"
#include "../handlers/KeyBoardHandler.h"
class __declspec(dllexport) KeyCodeAdapter
{
private:
	KeyBoardHandler _handler;

public:
	KeyCodeAdapter();
	KeyEnum translateToEnum(SDL_Event event);
	void handleEvent(KeyEnum type, Models::Sprite* sprite, Models::Shape shape);
};