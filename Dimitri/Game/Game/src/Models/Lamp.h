#pragma once
#include "IInteractable.h"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Models
	*/
	namespace Models {
		/**
		*	Contains all code necessary for the wall object
		*/
		class Lamp : public Game::Models::IInteractable {
		public:
			Lamp(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			void initialize_textures();
			void interact();
		};
	}
}