#pragma once
#include "InputController.h"
#include "WindowController.h"
#include "LevelController.h"
#include "../Models/Level.h"
#include <memory>
/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the controllers
	*/
	namespace Controllers {
		/**
		*	Contains code to connect input, window and level controllers and start the application
		*/
		class MainController {
		private:
			
			/**
			*	Input Controller
			*/
			std::shared_ptr<Controllers::InputController> _input_controller;
			/**
			*	Window Controller
			*/
			std::shared_ptr<Controllers::WindowController> _window_controller;
			/**
			*	Level Controller
			*/
			std::shared_ptr<Controllers::LevelController> _level_controller;
		public:
			MainController();

			/**
			*	Starts polling input controller
			*/
			void run();
		};
	}
}