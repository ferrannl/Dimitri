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
		* \class OpenPauseLevelViewCommand
		* \brief Class contains the method to open the pause level view
		*/
		class OpenPauseLevelViewCommand : public Command {
		public:
			OpenPauseLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the pause level view
			*/
			void execute(int param) override;
		};
	}
}