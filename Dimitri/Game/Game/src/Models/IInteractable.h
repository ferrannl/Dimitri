#pragma once
#include "IObject.h"
/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Models
	*/
	namespace Models {
		/**
		*	Interface for all interactables used in game for example switch, door, or camera
		*/
		class IInteractable : public Game::Models::IObject{
		public:
			IInteractable(int x, int y, int z, int height, int width);
			
			/**
			*	Virtual method to for example change object state
			*/
			virtual void interact() = 0;
		};
	}
}