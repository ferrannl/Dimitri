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
		*	Contains all code necessary for the Switch object
		*/
		class Switch : public Game::Models::IInteractable {
		public:
			Switch(int x, int y, int z, int height, int width);
			void initialize_textures();
			void interact();
		};
	}
}