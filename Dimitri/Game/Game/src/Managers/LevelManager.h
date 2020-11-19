#pragma once
#include <memory>

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Controllers
	*/
	namespace Controllers {
		/**
		*	Predefine Input Controller
		*/
		class InputController;
		/**
		*	Predefine Window Controller
		*/
		class WindowController;
		/**
		*	Predefine Level Controller
		*/
		class LevelController;
		/**
		*	Predefine Home Controller
		*/
		class HomeController;
	}
	/**
	*	Namespace for the Managers
	*/
	namespace Managers {
		/**
		*	Contains all code necessary for the button object
		*/
		class LevelManager {
		private:
			/**
			*	Input Controller
			*/
			std::shared_ptr<Game::Controllers::InputController> _input_controller;
			/**
			*	Level Controller
			*/
			std::shared_ptr<Game::Controllers::LevelController> _level_controller;
			/**
			*	Home Controller
			*/
			std::shared_ptr<Game::Controllers::HomeController> _home_controller;
			/**
			*	Window Controller
			*/
			std::shared_ptr<Game::Controllers::WindowController> _window_controller;
		public:
			LevelManager(std::shared_ptr<Game::Controllers::InputController> input_controller, std::shared_ptr<Game::Controllers::LevelController> level_controller, std::shared_ptr<Game::Controllers::WindowController> window_controller, std::shared_ptr<Game::Controllers::HomeController> home_controller);
			/**
			*	Loads a level 
			*/
			void load_level();
		};
	}
}