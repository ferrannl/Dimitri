#include "EventFacade.h"

EventFacade::EventFacade()
{
}

EventEnum EventFacade::translateToEnum(SDL_Event event)
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

		switch (event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			return EventEnum::MOUSE_PRESSED;
		case SDL_MOUSEMOTION:
			return EventEnum::MOUSE_MOTION;
		}
}

void EventFacade::handle_input(SDL_Event event, Models::Sprite* sprite, Models::Shape shape)
{
	EventEnum eventEnum = translateToEnum(event);

	if (event.type == SDL_KEYDOWN)
	{
		_handler = new KeyBoardHandler();
	} else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		_handler = new MouseHandler();
	}
	else {
		return;
	}
	_handler->handle_event(eventEnum, sprite, shape);
}
