#include "EventFacade.h" 
using namespace Input;

Facades::EventFacade::EventFacade()
{
    _event = {};        
}

Enums::EventEnum Facades::EventFacade::poll_event()
{
	
	if (SDL_PollEvent(&_event) != 0)
	{
        switch (_event.type) {
        case SDL_KEYDOWN:
            _input_adapter = std::make_shared<Adapters::KeyBoardAdapter>();
            return _input_adapter->translate_to_enum(_event);
        case SDL_MOUSEBUTTONDOWN:
            _input_adapter = std::make_shared<Adapters::MouseAdapter>();
            return _input_adapter->translate_to_enum(_event);
        case SDL_QUIT:
            return Enums::EventEnum::KEY_PRESS_QUIT;
        default:
            return Enums::EventEnum::NOT_SUPPORTED;
        }
	}
}
