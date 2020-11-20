#pragma once

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the enums
	*/
	namespace Enums {
		/**
		*	Contains different level state enums for the level
		*/
		enum class LevelStateEnum
		{
			ACTIVE,
			WIN,
			GAME_OVER,
			PAUSED,
			INACTIVE
		};
	}
}