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
		* \class OpenHelpViewCommand
		* \brief Class contains the method to open the help view
		*/
		class OpenHelpViewCommand : public Command {
		public:
			OpenHelpViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the help view
			*/
			void execute() override;
		};
	}
}