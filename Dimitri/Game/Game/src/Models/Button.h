#pragma once
#include "IInteractable.h"
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Models
	*/
	namespace Models {
		/**
		*	Contains all code necessary for the button object
		*/
		class Button : public Game::Models::IInteractable {
		protected:
			int _scene_height;
		public:
			Button(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height);
			virtual void initialize_textures() = 0;
			void update(const Game::Events::InputEvent& object);
			virtual void interact() = 0;
		};
	}
}