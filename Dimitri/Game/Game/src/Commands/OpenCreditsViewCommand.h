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
		* \brief Class contains the method to open the credits view
		*/
		class OpenCreditsViewCommand : public Command {
		public:
			OpenCreditsViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the credits view
			*/
			void execute() override;
		};
	}
}