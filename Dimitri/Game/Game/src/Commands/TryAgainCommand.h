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
		* \class LoadLevelCommand
		* \brief Class contains the method to load the level
		*/
		class TryAgainCommand : public Command {
		public:
			TryAgainCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Restarts the level
			*/
			void execute(int param) override;
		};
	}
}