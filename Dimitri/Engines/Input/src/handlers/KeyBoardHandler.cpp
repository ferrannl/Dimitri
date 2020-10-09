#include "KeyBoardHandler.h"

KeyBoardHandler::KeyBoardHandler()
{
}

void KeyBoardHandler::handle_event(const EventEnum num, Models::Sprite* sprite, Models::Shape shape) const
{
	switch (num)
	{
	case EventEnum::KEY_PRESS_RIGHT:
		shape.move_x(1);
		sprite->set_x(shape.get_x());
		break;
	case EventEnum::KEY_PRESS_LEFT:
		shape.move_x(-1);
		sprite->set_x(shape.get_x());
		break;
	case EventEnum::KEY_PRESS_UP:
		shape.move_y();
		sprite->set_y(shape.get_y());
		break;
	default:
		break;
	}
}