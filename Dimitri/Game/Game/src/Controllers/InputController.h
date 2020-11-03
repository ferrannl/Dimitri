#pragma once
#include <iostream>
#include <src\Controllers\InputController.h>

namespace Game {
	namespace Controllers {
		class InputController : public Utility::Interfaces::IObserver<Input::Enums::EventEnum>, public std::enable_shared_from_this<InputController> {
		private:
			std::unique_ptr<Input::Controllers::InputController> _input_controller;
		public:
			InputController();
			void poll_events();
			void update(const Input::Enums::EventEnum& object);
		};
	}
}
