#pragma once
#include "Object.h"

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
		* \class Interactable
		* \brief Class contains the methods to be able to interact with an Object
		*/
		class Interactable : public Object{
		public:
			Interactable(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center);
			
			/**
			* \brief Interact with this object
			*/
			virtual void interact(Controllers::LevelController* ctrl = NULL) = 0;
		};
	}
}