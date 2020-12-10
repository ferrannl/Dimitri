#pragma once
#include "InputController.h"
#include "WindowController.h"
#include "LevelController.h"
#include "HomeController.h"
#include "CreditsController.h"
#include "AdvertisementController.h"
#include "HelpController.h"
#include "../Models/Level.h"
#include "../Mediators/BaseComponent.h"
#include "../Managers/LevelManager.h"

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
		* \class MainController
		* \brief Class contains the methods to navigate through Views, connect the code to connect Input-, Window- and LevelController and start the application
		*/
		class MainController : public Utility::Interfaces::IObserver<Events::InputEvent>, public std::enable_shared_from_this<MainController>, public Mediators::BaseComponent {
		private:
			/**
			* \brief An instance of the InputController
			*/
			std::shared_ptr<Controllers::InputController> _input_controller;

			/**
			* \brief An instance of the AudioController
			*/
			std::shared_ptr<Controllers::AudioController> _audio_controller;

			/**
			* \brief An instance of the Level Manager
			*/
			std::shared_ptr<Managers::LevelManager> _level_manager;

			/**
			* \brief An instance of the WindowController
			*/
			std::shared_ptr<Controllers::WindowController> _window_controller;

			/**
			* \brief An instance of the LevelController
			*/
			std::shared_ptr<Controllers::LevelController> _level_controller;

			/**
			* \brief An instance of the HomeController
			*/
			std::shared_ptr<Controllers::HomeController> _home_controller;

			/**
			* \brief An instance of the CreditsController
			*/
			std::shared_ptr<Controllers::CreditsController> _credits_controller;

			/**
			* \brief An instance of the HelpController
			*/
			std::shared_ptr<Controllers::HelpController> _help_controller;

			/**
			* \brief An instance of the AdvertisementController
			*/
			std::shared_ptr<Controllers::AdvertisementController> _advertisement_controller;
		public:
			MainController();

			/**
			* \brief Creates the Window and starts polling events
			*/
			void run();

			/**
			* \brief Receives updates from the InputController
			*/
			void update(const Events::InputEvent& object);

			/**
			* \brief Returns the InputController
			*/
			std::shared_ptr<Controllers::InputController> get_input_controller() const;

			/**
			* \brief Returns the AudioController
			*/
			std::shared_ptr<Controllers::AudioController> get_audio_controller() const;

			/**
			* \brief Returns the Level Manager
			*/
			std::shared_ptr<Managers::LevelManager> get_level_manager() const;

			/**
			* \brief Returns the WindowController
			*/
			std::shared_ptr<Controllers::WindowController> get_window_controller() const;

			/**
			* \brief Returns the LevelController
			*/
			std::shared_ptr<Controllers::LevelController> get_level_controller() const;

			/**
			* \brief Returns the HomeController
			*/
			std::shared_ptr<Controllers::HomeController> get_home_controller() const;

			/**
			* \brief Returns the CreditsController
			*/
			std::shared_ptr<Controllers::CreditsController> get_credits_controller() const;

			/**
			* \brief Returns the HelpController
			*/
			std::shared_ptr<Controllers::HelpController> get_help_controller() const;
		};
	}
}
