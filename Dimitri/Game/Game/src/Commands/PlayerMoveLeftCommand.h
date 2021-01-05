#pragma once
#include "Command.h"
#include "../Enums/DirectionEnum.h"

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
		* \class PlayerMoveLeftCommand
		* \brief Class contains the method to make the player move left
		*/
		class PlayerMoveLeftCommand : public Command {
		public:
			PlayerMoveLeftCommand(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Makes the player move left
			*/
			void execute(int param) override;
		};
	}
}