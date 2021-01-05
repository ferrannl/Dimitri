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
		* \class IncreaseGameSpeedCommand
		* \brief Class contains the method to Increase the gameplay speed
		*/
		class IncreaseGameSpeedCommand : public Command {
		public:
			IncreaseGameSpeedCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Increases the gamespeed
			*/
			void execute(int param) override;
		};
	}
}