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
		*	Contains different level state enums for the level
		*/
		enum class LevelStateEnum
		{
			TRANSITION,
			ACTIVE,
			WIN,
			GAME_OVER,
			PAUSED,
			INACTIVE
		};
	}
}