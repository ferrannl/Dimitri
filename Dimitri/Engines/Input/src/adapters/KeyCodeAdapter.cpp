#include "KeyCodeAdapter.h"



KeyCodeAdapter::~KeyCodeAdapter()
{
}

KeyCodeAdapter::KeyCodeAdapter()
{
	_handler = KeyBoardHandler();
}

void KeyCodeAdapter::handleEvent(KeyEnum type, Models::Sprite* sprite, Models::Shape shape)
{
	_handler.handleEvent(type, sprite, shape);
	/*switch (type)
	{
	case KEY_PRESS_LEFT:
		break;
	case KEY_PRESS_RIGHT:
		break;
	case KEY_PRESS_DOWN:
		break;
	case KEY_PRESS_UP:
		break;
	case KEY_PRESS_JUMP:
		break;
	}*/

}
KeyEnum KeyCodeAdapter::translateToEnum(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_LEFT:
		return KeyEnum::KEY_PRESS_LEFT;
	case SDLK_RIGHT:
		return KeyEnum::KEY_PRESS_RIGHT;
	case SDLK_UP:
		return KeyEnum::KEY_PRESS_UP;
	case SDLK_DOWN:
		return KeyEnum::KEY_PRESS_DOWN;
	case SDLK_SPACE:
		return KeyEnum::KEY_PRESS_JUMP;
	}
}
