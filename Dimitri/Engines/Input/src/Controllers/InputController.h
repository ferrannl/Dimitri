#pragma once
#include "../Facades/EventFacade.h"
#include "../Facades/MouseFacade.h"
#include "../../../../Utility/src/Interfaces/IObservable.h"
#include "../../../../Utility/src/Interfaces/IObserver.h"
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

namespace Input {
	namespace Controllers {
		class __declspec(dllexport) InputController : public Utility::Interfaces::IObservable<Enums::EventEnum> {
		private:
			//shared press events
			std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>> _observer;

			//Facades
			std::unique_ptr<Facades::MouseFacade> _mouse_facade;
			std::unique_ptr<Facades::EventFacade> _event_facade;

		public:
			InputController();
			std::tuple<int, int> get_mouse_position();

			void notify(const Enums::EventEnum& object);
			void subscribe(std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>> observer);
			void poll_events();
		};
	}
}
