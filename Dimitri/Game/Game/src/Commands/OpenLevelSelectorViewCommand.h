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
		* \class OpenLevelSelectorViewCommand
		* \brief Class contains the method to open the cheats view
		*/
		class OpenLevelSelectorViewCommand : public Command {
		public:
			OpenLevelSelectorViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the Level Selector view
			*/
			void execute() override;
		};
	}
}