#pragma once
#include "../Button.h"
#include <cstdlib>

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
			class ExitButton : public Game::Models::Button {
			private:
			public:
				ExitButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height);
				void interact();
				void update(const Game::Events::InputEvent& object);
			};
		}
	}
}