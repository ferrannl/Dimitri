#pragma once
#include "../IButton.h"
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
		*	Namespace for the Buttons
		*/
		namespace Buttons {
			class ExitButton : public Game::Models::IButton {
			public:
				ExitButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height);
				/**
				*	Initializes the textures for an object
				*/
				void initialize_textures();
				/**
				*	Action when the button is pressed
				*/
				void interact();
			};
		}
	}
}