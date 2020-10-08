#pragma once
#include "../../../Graphics/src/Models/Sprite.h"
#include "../enums/EventEnum.cpp"
#include "../../../PhysicsCollision/src/Models/Shape.h"
class __declspec(dllexport) IInputHandler
{
public:
	virtual void handle_event(const EventEnum num, Models::Sprite* sprite, Models::Shape shape)const = 0 ;
};