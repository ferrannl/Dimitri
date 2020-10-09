#include "MouseHandler.h"

MouseHandler::MouseHandler()
{
	_facade = std::make_unique<MouseFacade>();
}

void MouseHandler::handle_event(const EventEnum num, Models::Sprite* sprite, Models::Shape shape) const
{
	int x, y;
	switch (num)
	{
	case EventEnum::MOUSE_PRESSED:
		std::tie(x,y) = _facade->get_mouse_position();
		break;
	case EventEnum::MOUSE_MOTION:
		std::tie(x, y) = _facade->get_mouse_position();
		break;
	default:
		break;
	}
}