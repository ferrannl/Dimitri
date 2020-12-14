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
		* \class SetCheatsInfiniteCommand
		* \brief Class contains the method to open the help view
		*/
		class SetCheatInfiniteCommand : public Command {
		public:
			SetCheatInfiniteCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the help view
			*/
			void execute() override;
		};
	}
}