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
		* \class Enemy
		* \brief Class contains the data of the Enemy
		*/
		class Enemy : public Models::Updatable {
		private:
			/**
			* \brief The max amount of jumps the Enemy is allowed to make
			*/
			const int _max_amount_of_jumps = 1;

			/**
			* \brief Last x position of last update of the Enemy
			*/
			int _lastx;

			/**
			* \brief Last y position of last update of the Enemy
			*/
			int _lasty;

			/**
			* \brief The amount of jumps the Enemy has made
			*/
			int _jumps;

			/**
			* \brief Handles the walk animation of the Enemy
			*/
			void walk();

			/**
			* \brief Handles the idle animation of the Enemy
			*/
			void idle();
		public:
			Enemy(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Checks if the Enemy can jump and then initiates jump
			*/
			bool jump();

			/**
			* \brief Resets the jump counter of the Enemy
			*/
			void reset_jump();

			/**
			* \brief Updates the Enemy
			*/
			void update_object(Controllers::LevelController* ctrl = NULL);

			/**
			* \brief Checks the state of the Enemy with by checking the increase of x and or y
			*/
			void update_state();
		};
	}
}