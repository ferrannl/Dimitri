#pragma once
#include "InputController.h"
#include "WindowController.h"
#include "../Models/Level.h"
#include <memory>
namespace Game {
	namespace Controllers {
		class MainController {
		private:
			std::shared_ptr<Models::Level> _level;
			std::shared_ptr<Controllers::InputController> _input_controller;
			std::shared_ptr<Controllers::WindowController> _window_controller;
		public:
			MainController();
		};
	}
}