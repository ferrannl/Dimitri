#include "EventFacade.h"

EventFacade::EventFacade()
{
}

EventEnum EventFacade::translate_to_enum(const SDL_Event event)
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

void EventFacade::handle_input(const SDL_Event event,  Models::Sprite* sprite, Models::Shape shape) 
{
	EventEnum eventEnum = translate_to_enum(event);

	if (event.type == SDL_KEYDOWN)
	{
		_handler = std::make_unique<KeyBoardHandler>();
	} else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		_handler = std::make_unique<MouseHandler>();
	}
	else {
		return;
	}
	_handler->handle_event(eventEnum, sprite, shape);
}
