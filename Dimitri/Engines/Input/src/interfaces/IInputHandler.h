#pragma once
#include "../../../Graphics/src/Models/Sprite.h"
#include "../enums/EventEnum.cpp"
#include "../../../PhysicsCollision/src/Models/Shape.h"
class __declspec(dllexport) IInputHandler
{
public:
	IInputHandler();
	virtual void handle_event(EventEnum num, Models::Sprite* sprite, Models::Shape shape) = 0;
};