#include "EventAdapter.h"

Enums::EventEnum Adapters::EventAdapter::translate_to_enum(const SDL_Event event)
{
    switch (event.type) {
    case SDL_KEYDOWN:
        _input_adapter = std::make_shared<Adapters::KeyBoardAdapter>();
        return _input_adapter->translate_to_enum(event);
    case SDL_MOUSEBUTTONDOWN: 
        _input_adapter = std::make_shared<Adapters::MouseAdapter>();
        return _input_adapter->translate_to_enum(event);
    }
}
