#include "KeyBoardHandler.h"

KeyBoardHandler::KeyBoardHandler()
{

}

void KeyBoardHandler::handleEvent(KeyEnum num, Models::Sprite* sprite, Models::Shape shape)
{
	switch (num)
	{
	case KeyEnum::KEY_PRESS_RIGHT:
		shape.set_x(1);
		sprite->set_x(static_cast<int>(shape.get_x()));
		break;
	case KeyEnum::KEY_PRESS_LEFT:
		shape.set_x(-1);
		sprite->set_x(static_cast<int>(shape.get_x()));
		break;
	case KeyEnum::KEY_PRESS_UP:
		shape.set_y();
		sprite->set_y(static_cast<int>(shape.get_y()));
		break;
	default:
		break;
	}
}