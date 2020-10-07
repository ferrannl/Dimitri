#include "KeyCodeAdapter.h"

KeyCodeAdapter::KeyCodeAdapter()
{
	_handler = KeyBoardHandler();
}

void KeyCodeAdapter::handleEvent(KeyEnum type, Models::Sprite* sprite, Models::Shape shape)
{
	_handler.handleEvent(type, sprite, shape);

}
KeyEnum KeyCodeAdapter::translateToEnum(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_LEFT:
		return KEY_PRESS_LEFT;
	case SDLK_RIGHT:
		return KEY_PRESS_RIGHT;
	case SDLK_UP:
		return KEY_PRESS_UP;
	case SDLK_DOWN:
		return KEY_PRESS_DOWN;
	case SDLK_SPACE:
		return KEY_PRESS_JUMP;
	}
}
