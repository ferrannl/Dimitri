#pragma once
#include <SDL.h>
#include "../enums/EventEnum.cpp"
#include <string>
#include <vector>
#include "../../../PhysicsCollision/src/Models/Shape.h"
#include "../../../Graphics/src/Models/Sprite.h"
#include <tuple>
#include "../interfaces/IInputAdapter.h"
#include "../Adapters/EventAdapter.h"

namespace Facades {
	class __declspec(dllexport) EventFacade {
	private:
		std::unique_ptr<Adapters::EventAdapter> _event_adapter;
	public:

		EventFacade();
		Enums::EventEnum poll_event();
	};
}

