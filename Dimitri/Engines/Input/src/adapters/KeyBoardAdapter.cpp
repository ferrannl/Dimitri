#include "KeyBoardAdapter.h"

Enums::EventEnum Adapters::KeyBoardAdapter::translate_to_enum(const SDL_Event event)const
{
	switch (event.key.keysym.sym)
	{
        case SDLK_0:
            return Enums::EventEnum::KEY_PRESS_0;
        case SDLK_1:
            return Enums::EventEnum::KEY_PRESS_1;
        case SDLK_2:
            return Enums::EventEnum::KEY_PRESS_2;
        case SDLK_3:
            return Enums::EventEnum::KEY_PRESS_3;
        case SDLK_4:
            return Enums::EventEnum::KEY_PRESS_4;
        case SDLK_5:
            return Enums::EventEnum::KEY_PRESS_5;
        case SDLK_6:
            return Enums::EventEnum::KEY_PRESS_6;
        case SDLK_7:
            return Enums::EventEnum::KEY_PRESS_7;
        case SDLK_8:
            return Enums::EventEnum::KEY_PRESS_8;
        case SDLK_9:
            return Enums::EventEnum::KEY_PRESS_9;
	    case SDLK_LEFT:
		    return Enums::EventEnum::KEY_PRESS_LEFT;
	    case SDLK_RIGHT:
		    return Enums::EventEnum::KEY_PRESS_RIGHT;
	    case SDLK_UP:
		    return Enums::EventEnum::KEY_PRESS_UP;
        default:
            return Enums::EventEnum::NOT_SUPPORTED;
	}
}