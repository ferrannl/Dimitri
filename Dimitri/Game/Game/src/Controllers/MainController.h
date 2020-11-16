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
		class MainController : public Utility::Interfaces::IObserver<Events::InputEvent>, public std::enable_shared_from_this<MainController>, public Utility::Interfaces::IObserver<Enums::LevelStateEnum> {
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
			
			/**
			*	Update from Game::Controllers::InputController
			*/
			void update(const Events::InputEvent& object);

			/**
			*	Update from LevelController
			*/
			void update(const Enums::LevelStateEnum& object);
		};
	}
}