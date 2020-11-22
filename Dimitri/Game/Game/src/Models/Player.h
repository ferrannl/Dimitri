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
		*	Contains all code necessary for the player object
		*/
		class Player : public Game::Models::IObject{
		private: 
			const int _max_amount_of_jumps = 2;
			int _jumps;
		public:
			Player(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			void initialize_textures();
			bool jump();
			void reset_jump();
		};
	}
}