#include "KeyBoardHandler.h"

KeyBoardHandler::KeyBoardHandler()
{

}

void KeyBoardHandler::handleEvent(KeyEnum num, Models::Sprite* sprite, Models::Shape shape)
{
	switch (num)
	{
	case KeyEnum::KEY_PRESS_RIGHT:
		//std::cout << shapes[0].get_x() + 50;
		shape.set_x(1);
		sprite->set_x(static_cast<int>(shape.get_x()));
		break;
	case KeyEnum::KEY_PRESS_LEFT:
		/*shapes[0].set_x(shapes[0].get_x() - 1);*/
		shape.set_x(-1);
		sprite->set_x(static_cast<int>(shape.get_x()));
	case KeyEnum::KEY_PRESS_JUMP:
		shape.set_y();
		sprite->set_y(static_cast<int>(shape.get_y()));
	default:
		//sprites[0]->set_x(static_cast<int>(shapes[0].get_x() + 50));
		break;
	}
}