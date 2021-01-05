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
		* \class PlayerJumpCommand
		* \brief Class contains the method to make the player jump
		*/
		class PlayerJumpCommand : public Command {
		public:
			PlayerJumpCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Makes the player jump
			*/
			void execute(int param) override;
		};
	}
}