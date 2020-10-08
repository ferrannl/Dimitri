#pragma once
#include "../interfaces/IInputHandler.h"
#include "../../adapters/MouseFacade.h"
#include <iostream>

class __declspec(dllexport) MouseHandler : public IInputHandler {
private:
	std::unique_ptr<MouseFacade> _facade;
public:
	MouseHandler();
	void handle_event(const EventEnum num, Models::Sprite* sprite, Models::Shape shape) const;
};