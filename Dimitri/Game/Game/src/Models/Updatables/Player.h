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
			* \brief The speed of the player
			*/
			float _speed;

			/**
			* \brief The max amount of jumps the player is allowed to make
			*/
			int _max_amount_of_jumps = 2;

			/**
			* \brief Last x position of last update of the player
			*/
			float _lastx;

			/**
			* \brief Last y position of last update of the player
			*/
			float _lasty;

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

			/**
			* \brief Handles the jump_hud animation of the player
			*/
			void jump_animation();
		public:
			Player(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Sets the speed of the player
			*/
			void set_speed(float speed)override;

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
			void update_object(Controllers::LevelController* ctrl = nullptr);

			/**
			* \brief Checks the state of the player with by checking the increase of x and or y
			*/
			void update_state();

			/**
			* \brief Returns the speed of the player
			*/
			float get_speed()const;
			
			/**
			* \brief Returns Extra Textures
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_extra_textures();

			/**
			* \brief sets max amount of jumps
			*/
			void set_jumps(int jumps);

			/**
			* \brief Clears extra textures
			*/
			void clear_extra_textures();
		};
	}
}
