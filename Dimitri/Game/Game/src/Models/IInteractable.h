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
		*	Interface for all interactables used in game for example switch, door, or camera
		*/
		class IInteractable : public Game::Models::IObject{
		public:
			IInteractable(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
			
			/**
			*	Virtual method to for example change object state
			*/
			virtual void interact() = 0;
		};
	}
}