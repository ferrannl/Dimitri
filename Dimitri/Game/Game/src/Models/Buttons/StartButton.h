#pragma once
#include "../Button.h"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Models
	*/
	namespace Models {
		/**
		*	Contains all code necessary for the button object
		*/
		namespace Buttons {
			class StartButton : public Game::Models::Button {
			public:
				StartButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height);
				void interact();
			};
		}
	}
}