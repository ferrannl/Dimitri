#pragma once
#include "IObject.h"

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
		class Button : public Game::Models::IObject {
		public:
			Button(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			void initialize_textures();
		};
	}
}