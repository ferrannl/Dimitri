#pragma once
#include "Command.h"

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
		* \class ExitGameCommand
		* \brief Class contains the method to exit the game
		*/
		class ExitGameCommand : public Command {
		public:
			ExitGameCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Exits the game
			*/
			void execute() override;
		};
	}
}