#pragma once
#include "IObject.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {
		/**
		* \class IInteractable
		* \brief Class contains the methods to be able to interact with an IObject
		*/
		class IInteractable : public Game::Models::IObject{
		public:
			IInteractable(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			
			/**
			* \brief Interact with this object
			*/
			virtual void interact() = 0;
		};
	}
}