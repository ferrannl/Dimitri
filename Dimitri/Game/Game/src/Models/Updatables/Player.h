#pragma once
#include "../Abstract/Updatable.h"

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
		* \class Player
		* \brief Class contains the data of the Player
		*/
		class Player : public Models::Updatable {
		private: 
			const int _max_amount_of_jumps = 2;
			int _lastx;
			int _lasty;
			int _jumps;
			void walk();
			void idle();
		public:
			Player(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();


			bool jump();
			void reset_jump();
			void update_object(Controllers::LevelController* ctrl = NULL);
			void update_state();
		};
	}
}