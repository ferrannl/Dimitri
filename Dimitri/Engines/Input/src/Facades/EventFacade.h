#pragma once
#include "../Adapters/KeyBoardAdapter.h"
#include "../Adapters/MouseAdapter.h"
#include <memory>
#include <SDL.h>

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else 
#define INPUT_API __declspec(dllimport)
#endif
#else
#define INPUT_API
#endif


namespace Facades {
	class INPUT_API EventFacade {
	private:
		SDL_Event _event;
		std::shared_ptr<Interfaces::IInputAdapter> _input_adapter;
	public:

		EventFacade();
		Enums::EventEnum poll_event();
	};
}

