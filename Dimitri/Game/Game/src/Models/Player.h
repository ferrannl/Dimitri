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
		* \class Player
		* \brief Class contains the data of the Player
		*/
		class Player : public Game::Models::IObject{
		private: 
			/**
			* \brief Max amount of jumps(for resetting _jumps when touching tile)
			*/
			int _max_amount_of_jumps = 2;

			/**
			* \brief Current amount of jumps
			*/
			int _jumps;
		public:
			Player(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Checks if player is able to jump and if so lowers _jumps int
			*/
			bool jump();

			/**
			* \brief Resets _jumps to _max_amount_of_jumps, called when touching floor
			*/
			void reset_jump();

			/**
			* \brief sets max amount of jumps
			*/
			void set_jumps(int jumps);
		};
	}
}