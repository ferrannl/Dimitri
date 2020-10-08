#pragma once
#include "../interfaces/IInputHandler.h"
#include <iostream>
#include "../adapters/MouseAdapter.h"

class __declspec(dllexport) MouseHandler : public IInputHandler {
private:
	std::unique_ptr<MouseAdapter> _facade;
public:
	MouseHandler();
	void handle_event(const EventEnum num, Models::Sprite* sprite, Models::Shape shape) const;
};