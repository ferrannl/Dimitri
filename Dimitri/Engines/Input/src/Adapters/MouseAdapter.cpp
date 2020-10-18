#include "MouseAdapter.h"
using namespace Input;

Enums::EventEnum Adapters::MouseAdapter::translate_to_enum(const SDL_Event event) const {
	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		return Enums::EventEnum::MOUSE_PRESSED;
	case SDL_MOUSEMOTION:
		return Enums::EventEnum::MOUSE_MOTION;
	}
}