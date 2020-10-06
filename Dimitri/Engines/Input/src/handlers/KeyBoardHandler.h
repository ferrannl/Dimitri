#pragma once
#include "../enums/KeyEnum.cpp"
#include "../../../PhysicsCollision/src/Models/Shape.h"
#include "../../../Graphics/src/Models/Sprite.h"

class KeyBoardHandler {
public:

	KeyBoardHandler();
	~KeyBoardHandler();
	void handleEvent(KeyEnum, Models::Sprite* sprite, Models::Shape shape);
};
