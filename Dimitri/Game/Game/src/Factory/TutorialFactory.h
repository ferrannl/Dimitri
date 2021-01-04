#pragma once
#include <src/Models/Sprite.h>
#include "../Enums/TypeEnum.h"
#include "../Enums/DirectionEnum.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game.Factories
	* \brief Namespace for the factories
	*/
	namespace Factories {
		/**
		* \class Tutorialfactory
		* \brief Class contains the methods to create backgrounds
		*/
		class TutorialFactory {
		public:
			/**
			* \brief Creates the tutorial images
			*/
			std::shared_ptr<Graphics::Models::Sprite> create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state);
		};
	}
}