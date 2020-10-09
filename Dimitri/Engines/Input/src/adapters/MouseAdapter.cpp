#include "MouseAdapter.h"
MouseAdapter::MouseAdapter()
{
}

EventEnum MouseAdapter::translate_to_enum(const SDL_Event event)const
{
	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		return EventEnum::MOUSE_PRESSED;
	case SDL_MOUSEMOTION:
		return EventEnum::MOUSE_MOTION;
	}
}