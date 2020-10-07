#pragma once
#include "../enums/KeyEnum.cpp"
#include "../../../PhysicsCollision/src/Models/Shape.h"
#include "../../../Graphics/src/Models/Sprite.h"
#include <string>

class KeyBoardHandler {
public:
	KeyBoardHandler();
	void handleEvent(KeyEnum num, Models::Sprite* sprite, Models::Shape shape);
};
