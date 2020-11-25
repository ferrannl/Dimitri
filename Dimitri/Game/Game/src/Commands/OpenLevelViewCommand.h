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
		* \class OpenLevelViewCommand
		* \brief Class contains the method to open the level view
		*/
		class OpenLevelViewCommand : public Command {
		public:
			OpenLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the level view
			*/
			void execute() override;
		};
	}
}