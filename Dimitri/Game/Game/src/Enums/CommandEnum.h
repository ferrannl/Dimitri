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
		* \enum CommandEnum
		* \brief Enum Class contains the different command identifiers
		*/
		enum class CommandEnum
		{
			EXIT_GAME,
			LOAD_LEVEL,
			OPEN_CREDITS_VIEW,
			OPEN_HELP_VIEW,
			OPEN_HOME_VIEW,
			TOGGLE_FPS_VIEW,
			PLAYER_MOVE_LEFT,
			PLAYER_MOVE_RIGHT,
			PLAYER_JUMP,
			PLAYER_INTERACT,
			PAUSE_LEVEL,
			OPEN_WIN_LEVEL_VIEW,
			OPEN_PAUSE_LEVEL_VIEW,
			OPEN_GAME_OVER_LEVEL_VIEW,
			OPEN_LEVEL_VIEW,
		};
	}
}