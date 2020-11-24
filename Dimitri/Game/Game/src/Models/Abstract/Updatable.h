#pragma once
#include "Object.h"
#include "../../Enums/DirectionEnum.cpp"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	namespace Controllers {
		class LevelController;
	}

	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {
		/**
		* \class IInteractable
		* \brief Class contains the methods to be able to interact with an Object
		*/
		class Updatable : public Object {
		public:
			Updatable(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Interact with this object
			*/
			virtual void update_object(Controllers::LevelController* ctrl = NULL) = 0;
		};
	}
}