#pragma once
#include "IInteractable.h"
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"

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
		*	Contains all code necessary for the button object
		*/
		class Button : public Game::Models::IInteractable {
		protected:
			int _scene_height;
		public:
			Button(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height);
			void initialize_textures();
			void update(const Game::Events::InputEvent& object);
			virtual void interact() = 0;
		};
	}
}