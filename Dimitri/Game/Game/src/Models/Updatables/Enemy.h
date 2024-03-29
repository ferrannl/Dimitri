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
			* \brief Last x position of last update of the Enemy
			*/
			float _lastx;

			/**
			* \brief The x position where the enemy starts
			*/
			float _base_x;

			/**
			* \brief The left area where the enemy can see the player
			*/
			int _area_left;

			/**
			* \brief The right area where the enemy can see the player
			*/
			int _area_right;

			/**
			* \brief The top area where the enemy can see the player
			*/
			int _area_top;

			/**
			* \brief The bottom area where the enemy can see the player
			*/
			int _area_bottom;

			/**
			* \brief The direction where the enemy is walking
			*/
			int _moving_direction;

			/**
			* \brief Boolean for checking if the enemy is moving
			*/
			bool _standstill;

			/**
			* \brief Last y position of last update of the Enemy
			*/
			float _lasty;

			/**
			* \brief The amount of jumps the Enemy has made
			*/
			int _jumps;

			/**
			* \brief Bool to check if the alarm is playing
			*/
			bool _playing_alarm;

			/**
			* \brief Bool to check if the adaptive sound is playing
			*/
			bool _playing_adaptive;

			/**
			* \brief Handles the walk animation of the Enemy
			*/
			void walk();

			/**
			* \brief Handles the idle animation of the Enemy
			*/
			void idle();

			/**
			* \brief Handles the ai path logic of the Enemy
			*/
			void walk_in_area(Controllers::LevelController* ctrl);

			/**
			* \brief Handles the ai chase player logic of the Enemy
			*/
			void chase_player(Controllers::LevelController* ctrl);

			/**
			* \brief Handles the logic when the alarm should go off
			*/
			void play_alarm(Controllers::LevelController* ctrl);

			/**
			* \brief Handles the logic when the adaptive sound should play
			*/
			void play_adaptive(Controllers::LevelController* ctrl);
		public:
			Enemy(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center, int area_left, int area_right, int area_top, int area_bottom);

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