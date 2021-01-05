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
		* \class OpenLevelTransitionViewCommand
		* \brief Class contains the method to open the level transition view
		*/
		class OpenLevelTransitionViewCommand : public Command {
		public:
			OpenLevelTransitionViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the level transition view
			*/
			void execute(int param) override;
		};
	}
}