#pragma once
#include <iostream>
#include <src\Controllers\InputController.h>
#include "../Models/InputEvent.h"

namespace Game {
	namespace Controllers {
		class InputController : public Utility::Interfaces::IObserver<Input::Enums::EventEnum>, public std::enable_shared_from_this<InputController>, public Utility::Interfaces::IObservable<Game::Models::InputEvent> {
		private:
			std::unique_ptr<Input::Controllers::InputController> _input_controller;
			std::shared_ptr<Utility::Interfaces::IObserver<Game::Models::InputEvent>> _observer;
		public:
			InputController();
			void poll_events();
			void update(const Input::Enums::EventEnum& object);
			void notify(const Game::Models::InputEvent& object);
			void subscribe(std::shared_ptr<Utility::Interfaces::IObserver<Game::Models::InputEvent>> observer);
		};
	}
}
