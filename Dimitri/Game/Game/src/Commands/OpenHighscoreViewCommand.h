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
		* \class OpenHighscoreViewCommand
		* \brief Class contains the method to open the highscore view
		*/
		class OpenHighscoreViewCommand : public Command {
		public:
			OpenHighscoreViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the highscore view
			*/
			void execute() override;
		};
	}
}