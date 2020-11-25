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
		* \class PlayerInteractCommand
		* \brief Class contains the method to make the player interact
		*/
		class PlayerInteractCommand : public Command {
		public:
			PlayerInteractCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			void execute() override;
		};
	}
}