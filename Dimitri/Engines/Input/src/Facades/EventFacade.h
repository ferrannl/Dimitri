#pragma once
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

