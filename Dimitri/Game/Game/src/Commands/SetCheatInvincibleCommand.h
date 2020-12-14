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
		* \class SetCheatsInvincibleCommand
		* \brief Class contains the method to open the help view
		*/
		class SetCheatInvincibleCommand : public Command {
		public:
			SetCheatInvincibleCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the help view
			*/
			void execute() override;
		};
	}
}