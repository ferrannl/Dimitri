#include "MouseAdapter.h"
using namespace Input;

Enums::EventEnum Adapters::MouseAdapter::translate_to_enum(const SDL_Event event) const {
	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT) {
			return Enums::EventEnum::MOUSE_PRESSED_LEFT;
		}
		else if (event.button.button == SDL_BUTTON_RIGHT) {
			return Enums::EventEnum::MOUSE_PRESSED_RIGHT;
		}
		return Enums::EventEnum::NOT_SUPPORTED;
	case SDL_MOUSEMOTION:
		return Enums::EventEnum::MOUSE_MOTION;
	}
}