#pragma once
#include "IObject.h"

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
		*	Contains all code necessary for the player object
		*/
		class Player : public Game::Models::IObject{
		public:
			Player(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			void initialize_textures();
		};
	}
}