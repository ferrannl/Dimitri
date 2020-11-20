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
		class Car : public Game::Models::IInteractable {
		public:
			Car(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			void initialize_textures();
			void interact();
		};
	}
}