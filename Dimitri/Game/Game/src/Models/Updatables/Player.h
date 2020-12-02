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
			/**
			* \brief The max amount of jumps the player is allowed to make
			*/
			const int _max_amount_of_jumps = 2;

			/**
			* \brief Last x position of last update of the player
			*/
			int _lastx;

			/**
			* \brief Last y position of last update of the player
			*/
			int _lasty;

			/**
			* \brief The amount of jumps the player has made
			*/
			int _jumps;

			/**
			* \brief Handles the walk animation of the player
			*/
			void walk();

			/**
			* \brief Handles the idle animation of the player
			*/
			void idle();
		public:
			Player(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Checks if the player can jump and then initiates jump
			*/
			bool jump();

			/**
			* \brief Resets the jump counter of the player
			*/
			void reset_jump();

			/**
			* \brief Updates the player
			*/
			void update_object(Controllers::LevelController* ctrl = NULL);

			/**
			* \brief Checks the state of the player with by checking the increase of x and or y
			*/
			void update_state();
		};
	}
}