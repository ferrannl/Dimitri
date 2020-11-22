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
		private:
			int _switch_x;
		public:
			Switch(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			void initialize_textures();
			void interact(Controllers::LevelController* ctrl = NULL);
			void set_light(const int x);
		};
	}
}