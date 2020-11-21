#pragma once
#include "../Button.h"
#include "../../Managers/LevelManager.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {
		/**
		* \namespace Game::Buttons
		* \brief Namespace for the buttons in the game
		*/
		namespace Buttons {
			class StartButton : public Game::Models::Button {
			private:
				/**
				*	Level Manager
				*/
				std::shared_ptr<Game::Managers::LevelManager> _level_manager;
			public:
				StartButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::shared_ptr<Managers::LevelManager> level_manager);
				/**
				*	Action when the button is pressed
				*/
				void interact();
			};
		}
	}
}