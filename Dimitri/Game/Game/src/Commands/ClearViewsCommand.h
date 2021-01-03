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
		* \class ClearViewsCommand
		* \brief Class contains the method to close all views
		*/
		class ClearViewsCommand : public Command {
		public:
			ClearViewsCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Closes all views
			*/
			void execute(int param) override;
		};
	}
}