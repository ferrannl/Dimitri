#pragma once
#include "InputController.h"
#include "WindowController.h"
#include <memory>
namespace Game {
	namespace Controllers {
		class MainController {
		private:
			std::shared_ptr<Controllers::InputController> _input_controller;
			std::unique_ptr<Controllers::WindowController> _window_controller;
		public:
			MainController();
		};
	}
}