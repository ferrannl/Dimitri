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
		* \class OpenWinLevelViewCommand
		* \brief Class contains the method to open the win level view
		*/
		class OpenWinLevelViewCommand : public Command {
		public:
			OpenWinLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the win level view
			*/
			void execute(int param) override;
		};
	}
}