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
		* \class OpenCreditsViewCommand
		* \brief Class contains the method to open
		*/
		class OpenCreditsViewCommand : public Command {
		public:
			OpenCreditsViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			void execute() override;
		};
	}
}