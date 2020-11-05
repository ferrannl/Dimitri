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
		*	Contains all code necessary for the wall object
		*/
		class Wall : public Game::Models::IObject {
		public:
			Wall(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			void initialize_textures();
		};
	}
}