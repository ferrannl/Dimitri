#pragma once
#include "../Models/Abstract/Object.h"
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
		* \class ObjectFactory
		* \brief Class contains the methods to create tiles
		*/
		class ObjectFactory : public Interfaces::IFactory<Models::Object> {
		public:
			/**
			* \brief Creates the background
			*/
			std::shared_ptr<Models::Object> create(Enums::TypeEnum type, int x, int y, int z, int height, int width, Enums::DirectionEnum state);
		};
	}
}