#include "MouseFacade.h"
MouseFacade::MouseFacade()
{
}
std::tuple<int, int> MouseFacade::get_mouse_position()
{
	int x, y;
	SDL_GetGlobalMouseState(&x, &y);
	return std::tuple<int, int>{x, y};
}