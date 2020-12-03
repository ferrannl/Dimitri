#pragma once
#include <memory>
#include "../Enums/TypeEnum.h"
#include "../Enums/DirectionEnum.h"
#include <src/Models/Sprite.h>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game.Interfaces
	* \brief Namespace for interfaces
	*/
	namespace Interfaces {
		template<class T>
		/**
		* \class IFactory
		* \brief Class contains the methods which need to be implemented by factories
		*/
		class IFactory {
		public:
			/**
			* \brief Creates an object of type T
			*/
			virtual std::shared_ptr<T> create(Enums::TypeEnum type, int x, int y, int width, int height, int z, Enums::DirectionEnum state) = 0;
		};
	}
}