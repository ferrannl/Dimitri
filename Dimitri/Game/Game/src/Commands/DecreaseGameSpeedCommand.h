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
		* \class DecreaseGameSpeedCommand
		* \brief Class contains the method to decrease the gameplay speed
		*/
		class DecreaseGameSpeedCommand : public Command {
		public:
			DecreaseGameSpeedCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Decreases the gameplay speed
			*/
			void execute() override;
		};
	}
}