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
		* \class IInteractable
		* \brief Class contains the methods to be able to interact with an Object
		*/
		class Interactable : public Object{
		public:
			Interactable(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center);
			
			/**
			* \brief Interact with this object
			*/
			virtual void interact(Controllers::LevelController* ctrl = NULL) = 0;
		};
	}
}