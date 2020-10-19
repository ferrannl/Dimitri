#pragma once
#include "../../../Engines/Input/src/Enums/EventEnum.cpp"
#include "../../../Utility/src/Interfaces/IObserver.h"
#include "../../../Engines/Input/src/Controllers/InputController.h"
#include <iostream>
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
