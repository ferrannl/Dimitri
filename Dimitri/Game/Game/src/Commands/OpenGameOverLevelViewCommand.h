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
		* \class OpenGameOverLevelViewCommand
		* \brief Class contains the method to open the game over level view
		*/
		class OpenGameOverLevelViewCommand : public Command {
		public:
			OpenGameOverLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the game over level view
			*/
			void execute() override;
		};
	}
}