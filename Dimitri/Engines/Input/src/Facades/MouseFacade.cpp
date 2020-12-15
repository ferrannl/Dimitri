#include "MouseFacade.h"
#include <SDL_mouse.h>

using namespace Input;

std::tuple<int, int> Facades::MouseFacade::get_mouse_position() const
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return std::make_tuple(x, y);
}