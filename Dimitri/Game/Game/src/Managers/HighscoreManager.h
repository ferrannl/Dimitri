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
		class AudioController;
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
		* \class HighscoreManager
		* \brief Class contains the methods to manage the HighscoreView
		*/
		class HighscoreManager {
		private:
			/**
			* \brief An instance of the Input Controller
			*/
			std::shared_ptr<Game::Controllers::InputController> _input_controller;

			/**
			* \brief An instance of the Audio Controller
			*/
			std::shared_ptr<Game::Controllers::AudioController> _audio_controller;

			/**
			* \brief An instance of the Home Controller
			*/
			std::shared_ptr<Game::Controllers::HomeController> _home_controller;

			/**
			* \brief An instance of the Window Controller
			*/
			std::shared_ptr<Game::Controllers::WindowController> _window_controller;
		public:
			HighscoreManager(std::shared_ptr<Game::Controllers::InputController> input_controller, std::shared_ptr<Game::Controllers::AudioController> audio_controller, std::shared_ptr<Game::Controllers::WindowController> window_controller, std::shared_ptr<Game::Controllers::HomeController> home_controller);
		
			/**
			* \brief Loads the highscore
			*/
			void load_highscore();
		};
	}
}