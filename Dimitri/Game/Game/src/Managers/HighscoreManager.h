#pragma once
#include <memory>
#include "../Mediators/BaseComponent.h"
#include <src\Interfaces\IObserver.h>

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
		* \class Predefine Input Controller
		*/
		class InputController;
		/**
		* \class Predefine Window Controller
		*/
		class WindowController;
		/**
		* \class Predefine Level Controller
		*/
		class AudioController;
		/**
		* \class Predefine Home Controller
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
		class HighscoreManager : public Utility::Interfaces::IObserver<Events::InputEvent>, public Mediators::BaseComponent, public std::enable_shared_from_this<HighscoreManager> {
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

			/**
			* \brief Loads the Buttons
			*/
			void load_buttons();

			/**
			* \brief Calls on click event on the buttons if clicked
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			* \brief Returns the Textures from the Buttons
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;
		};
	}
}