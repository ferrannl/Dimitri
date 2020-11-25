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
		* \class LevelPauseCommand
		* \brief Class contains the method to pause and play the game
		*/
		class LevelPauseCommand : public Command {
		public:
			LevelPauseCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			void execute() override;
		};
	}
}