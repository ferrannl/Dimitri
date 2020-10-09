#include "EventFacade.h"

EventFacade::EventFacade()
{
}

EventEnum EventFacade::translate_to_enum(const SDL_Event event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		_adapter = std::make_shared<KeyBoardAdapter>();
		return _adapter->translate_to_enum(event);
	case SDL_MOUSEBUTTONDOWN:
		_adapter = std::make_shared<MouseAdapter>();
		return _adapter->translate_to_enum(event);
	}
}

void EventFacade::handle_input(const SDL_Event event,  Models::Sprite* sprite, Models::Shape shape)
{
	EventEnum eventEnum = translate_to_enum(event);

	if (event.type == SDL_KEYDOWN)
	{
		_handler = std::make_shared<KeyBoardHandler>();
	} else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		_handler = std::make_shared<MouseHandler>();
	}
	else {
		return;
	}
	_handler->handle_event(eventEnum, sprite, shape);
}
