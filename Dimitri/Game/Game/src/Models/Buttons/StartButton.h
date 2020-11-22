#pragma once
#include "../Button.h"
#include "../../Managers/LevelManager.h"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Models
	*/
	namespace Models {
		/**
		*	Namespace for the Buttons
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
				void interact(Controllers::LevelController* ctrl = NULL);
			};
		}
	}
}