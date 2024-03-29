#pragma once
#include "../Models/Abstract/Updatable.h"
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
		* \class UpdatableFactory
		* \brief Class contains the methods to create updatables
		*/
		class UpdatableFactory {
		public:
			/**
			* \brief Creates the updatable
			*/
			std::shared_ptr<Models::Updatable> create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state, float val = 0, bool val2 = true);
		};
	}
}
