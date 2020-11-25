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
		* \enum StateEnum
		* \brief Enum Class contains the different state enums for object states
		*/
		enum class TypeEnum
		{
			LEVER,
			FLOOR,
			WALL,
			CORNER,
			PLAYER,
			LAMP,
			BEAM,
			CAR,
			BG,
			BG_TOP1,
			BG_TOP2,
			SPIKE,
			CAM_VISION,
			CAMERA
		};
	}
}