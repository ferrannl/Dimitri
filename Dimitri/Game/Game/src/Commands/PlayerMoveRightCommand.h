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
		* \class PlayerMoveRightCommand
		* \brief Class contains the method to make the player move right
		*/
		class PlayerMoveRightCommand : public Command {
		public:
			PlayerMoveRightCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			void execute() override;
		};
	}
}