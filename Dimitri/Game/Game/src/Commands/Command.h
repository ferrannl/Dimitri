#pragma once
#include <memory>
#include "../Controllers/MainController.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Commands
	* \brief Namespace for the commands in the game
	*/
	namespace Commands {
		/**
		* \class Command
		* \brief Class contains the method to execute commands
		*/
		class Command {
		protected:
			/**
			* \brief An instance of the MainController
			*/
			std::shared_ptr<Controllers::MainController> _main_controller;
		public:
			Command(const std::shared_ptr<Controllers::MainController> main_controller) : _main_controller{ main_controller } {};

			/**
			* \brief Executes the logic of the command with parameter
			*/
			virtual void execute(int param) = 0;
		};
	}
}