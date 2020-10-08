#include "MouseAdapter.h"
MouseAdapter::MouseAdapter()
{
}
std::tuple<int, int> MouseAdapter::get_mouse_position() const
{
	int x, y;
	SDL_GetGlobalMouseState(&x, &y);
	return std::tuple<int, int>{x, y};
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