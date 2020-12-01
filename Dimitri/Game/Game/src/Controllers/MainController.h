#pragma once
#include "InputController.h"
#include "WindowController.h"
#include "LevelController.h"
#include "HomeController.h"
#include "../Models/Level.h"
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
		class MainController : public Utility::Interfaces::IObserver<Events::InputEvent>, public std::enable_shared_from_this<MainController>, public Utility::Interfaces::IObserver<Enums::LevelStateEnum> {
		private:
			/**
			* \brief An instance of the InputController
			*/
			std::shared_ptr<Controllers::InputController> _input_controller;

			/**
			* \brief An instance of the WindowController
			*/
			std::shared_ptr<Controllers::AudioController> _audio_controller;
			/**
			*	/brief An instance of the Level Manager
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
			* \brief Updates from LevelController
			*/
			void update(const Enums::LevelStateEnum& object);
		};
	}
}
