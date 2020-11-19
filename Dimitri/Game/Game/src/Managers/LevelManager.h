#pragma once
#include <memory>
/**
*	Namespace for the game
*/
namespace Game {
	namespace Controllers {
		class InputController;
		class WindowController;
		class LevelController;
		class HomeController;
	}
	/**
	*	Namespace for the Models
	*/
	namespace Managers {
		/**
		*	Contains all code necessary for the button object
		*/
		class LevelManager {
		private:
			std::shared_ptr<Game::Controllers::InputController> _input_controller;
			std::shared_ptr<Game::Controllers::LevelController> _level_controller;
			std::shared_ptr<Game::Controllers::HomeController> _home_controller;
			std::shared_ptr<Game::Controllers::WindowController> _window_controller;
		public:
			LevelManager(std::shared_ptr<Game::Controllers::InputController> input_controller, std::shared_ptr<Game::Controllers::LevelController> level_controller, std::shared_ptr<Game::Controllers::WindowController> window_controller, std::shared_ptr<Game::Controllers::HomeController> home_controller);
			void load_level();
		};
	}
}