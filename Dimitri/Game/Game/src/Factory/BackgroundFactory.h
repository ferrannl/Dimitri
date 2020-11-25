#pragma once
#include <src/Models/Sprite.h>
#include "../interfaces/IFactory.h"

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
		* \class BackgroundFactory
		* \brief Class contains the methods to create backgrounds
		*/
		class BackgroundFactory : public Interfaces::IFactory<Graphics::Models::Sprite> {
		public:
			/**
			* \brief Creates the background
			*/
			std::shared_ptr<Graphics::Models::Sprite> create(Enums::TypeEnum type, int x, int y, int width, int height, int z, Enums::DirectionEnum state);
		};
	}
}