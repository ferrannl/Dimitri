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
		* \class PauseLevelCommand
		* \brief Class contains the method to pause and resume the game
		*/
		class PauseLevelCommand : public Command {
		public:
			PauseLevelCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Pauses or resumes the game
			*/
			void execute() override;
		};
	}
}