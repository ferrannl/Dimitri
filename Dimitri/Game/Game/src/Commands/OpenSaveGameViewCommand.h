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
		* \class OpenSaveGameViewCommand
		* \brief Class contains the method to open the Save Game view
		*/
		class OpenSaveGameViewCommand : public Command
		{
		public:
			OpenSaveGameViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Opens the SaveGame view
			*/
			void execute() override;
		};
	}
}