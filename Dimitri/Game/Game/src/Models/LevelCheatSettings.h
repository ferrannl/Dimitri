#pragma once

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
		* \class LevelCheatSettings
		* \brief Class contains the data of the cheat settings
		*/
		class LevelCheatSettings {
		private:
			/**
			* \brief Contains jumps when not using cheats
			*/
			const int _normal_amount_of_jumps = 2;

			/**
			* \brief current amount of jumps
			*/
			int _amount_of_jumps;

			/**
			* \brief If player is invincible or not
			*/
			bool _invincible;
		public:
			LevelCheatSettings();

			/**
			* \brief Returns amount of jumps
			*/
			int get_amount_of_jumps() const;

			/**
			* \brief Returns invincibility
			*/
			bool get_invincible() const;

			/**
			* \brief Sets amount of jumps (changes between _normal_amount_of_jumps and max amount of jumps)
			*/
			void set_amount_of_jumps();

			/**
			* \brief Flips invincibility boolean
			*/
			void set_invincible();
		};
	}
}