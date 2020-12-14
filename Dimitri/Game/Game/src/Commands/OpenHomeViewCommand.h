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
		* \class OpenHomeViewCommand
		* \brief Class contains the method to open the home view
		*/
		class OpenHomeViewCommand : public Command {
		public:
			OpenHomeViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the home view
			*/
			void execute() override;
		};
	}
}