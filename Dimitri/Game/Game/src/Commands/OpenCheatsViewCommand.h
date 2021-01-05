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
		* \class OpenCheatsViewCommand
		* \brief Class contains the method to open the cheats view
		*/
		class OpenCheatsViewCommand : public Command {
		public:
			OpenCheatsViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the cheats view
			*/
			void execute(int param) override;
		};
	}
}