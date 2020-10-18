#pragma once
#include "../Adapters/KeyBoardAdapter.h"
#include "../Adapters/MouseAdapter.h"
#include <memory>
namespace Input {
	namespace Facades{
		class __declspec(dllexport) EventFacade {
		private:
			SDL_Event _event;
			std::shared_ptr<Interfaces::IInputAdapter> _input_adapter;
		public:

			EventFacade();
			Enums::EventEnum poll_event();
		};
	}
}
