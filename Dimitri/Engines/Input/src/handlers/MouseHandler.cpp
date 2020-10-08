#include "MouseHandler.h"
#include <iostream>

MouseHandler::MouseHandler()
{
	_facade = new MouseFacade();
}

void MouseHandler::handle_event(EventEnum num, Models::Sprite* sprite, Models::Shape shape)
{
	switch (num)
	{
	case EventEnum::MOUSE_PRESSED:
		int x, y;
		std::tie(x,y) = _facade->get_mouse_position();
		break;
	case EventEnum::MOUSE_MOTION:
		int x, y;
		std::tie(x, y) = _facade->get_mouse_position();
		break;
	default:
		break;
	}
}