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
		* \class ToggleFpsViewCommand
		* \brief Class contains the toggle the fps view
		*/
		class ToggleFpsViewCommand : public Command {
		public:
			ToggleFpsViewCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Toggles the fps view
			*/
			void execute(int param) override;
		};
	}
}