#pragma once
#include "../Abstract/Interactable.h"

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
		class Car : public Models::Interactable {
		public:
			Car(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center);
			void initialize_textures();
			void interact(Controllers::LevelController* ctrl = NULL);
		};
	}
}