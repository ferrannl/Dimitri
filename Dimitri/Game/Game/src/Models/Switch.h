#pragma once
#include "IInteractable.h"

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
		*	Contains all code necessary for the Switch object
		*/
		class Switch : public Game::Models::IInteractable {
		public:
			Switch(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			void initialize_textures();
			void interact();
		};
	}
}