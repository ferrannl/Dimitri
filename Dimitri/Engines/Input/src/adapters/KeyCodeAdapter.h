#pragma once
#include <SDL.h>
#include "../enums/KeyEnum.cpp"
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
	~KeyCodeAdapter();
	KeyEnum translateToEnum(SDL_Event event);
	void handleEvent(KeyEnum type, Models::Sprite* sprite, Models::Shape shape);
};