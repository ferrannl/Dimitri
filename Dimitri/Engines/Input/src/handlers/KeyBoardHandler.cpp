#include "KeyBoardHandler.h"

KeyBoardHandler::KeyBoardHandler()
{
}

void KeyBoardHandler::handle_event(EventEnum num, Models::Sprite* sprite, Models::Shape shape)
{
	switch (num)
	{
	case EventEnum::KEY_PRESS_RIGHT:
		shape.set_x(1);
		sprite->set_x(static_cast<int>(shape.get_x()));
		break;
	case EventEnum::KEY_PRESS_LEFT:
		shape.set_x(-1);
		sprite->set_x(static_cast<int>(shape.get_x()));
		break;
	case EventEnum::KEY_PRESS_UP:
		shape.set_y();
		sprite->set_y(static_cast<int>(shape.get_y()));
		break;
	default:
		break;
	}
}