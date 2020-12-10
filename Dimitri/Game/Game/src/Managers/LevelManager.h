#pragma once
#include <memory>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
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
	* \namespace Game::Managers
	* \brief Namespace for the managers in the game
	*/
	namespace Managers {
		/**
		* \class LevelManager
		* \brief Class contains the methods to manage the Levels
		*/
		class LevelManager {
		private:
			/**
			* \brief An instance of the Input Controller
			*/
			std::shared_ptr<Game::Controllers::InputController> _input_controller;

			/**
			* \brief An instance of the Level Controller
			*/
			std::shared_ptr<Game::Controllers::LevelController> _level_controller;

			/**
			* \brief An instance of the Home Controller
			*/
			std::shared_ptr<Game::Controllers::HomeController> _home_controller;

			/**
			* \brief An instance of the Window Controller
			*/
			std::shared_ptr<Game::Controllers::WindowController> _window_controller;
		public:
			LevelManager(std::shared_ptr<Game::Controllers::InputController> input_controller, std::shared_ptr<Game::Controllers::LevelController> level_controller, std::shared_ptr<Game::Controllers::WindowController> window_controller, std::shared_ptr<Game::Controllers::HomeController> home_controller);

			/**
			* \brief Loads a level
			*/
			void load_level();

			/**
			* \brief Returns an instance of the window controller
			*/
			std::shared_ptr<Game::Controllers::WindowController> get_window_controller()const;

		};
	}
}
