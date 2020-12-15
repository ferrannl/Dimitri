#pragma once

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Enums
	* \brief Namespace for the enums in the game
	*/
	namespace Enums {
		/**
		* \enum ButtonEnum
		* \brief Enum Class contains the different button identifiers
		*/
		enum class ButtonEnum
		{
			HOME,
			WIN_HOME,
			START,
			GAMEOVER_START,
			PAUSED_START,
			GAMEOVER_HOME,
			PAUSED_HOME,
			HELP,
			CREDITS,
			EXIT,
			HIGHSCORE,
			SAVE_GAMES,
			SAVE1,
			SAVE2,
			SAVE3,
			NEW1,
			NEW2,
			NEW3,
			CHEATS_CHECKBOX_INFINITE,
			CHEATS_CHECKBOX_INVINCIBLE,
			CHEATS,
			INCREASE_GAMEPLAY_SPEED,
			DECREASE_GAMEPLAY_SPEED
		};
	}
}