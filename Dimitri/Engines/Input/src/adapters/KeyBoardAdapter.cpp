#include "KeyBoardAdapter.h"
KeyBoardAdapter::KeyBoardAdapter()
{
}

EventEnum KeyBoardAdapter::translate_to_enum(const SDL_Event event)const
{
	switch (event.key.keysym.sym)
	{
	case SDLK_LEFT:
		return EventEnum::KEY_PRESS_LEFT;
	case SDLK_RIGHT:
		return EventEnum::KEY_PRESS_RIGHT;
	case SDLK_UP:
		return EventEnum::KEY_PRESS_UP;
	}
}