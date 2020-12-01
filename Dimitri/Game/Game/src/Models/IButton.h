#pragma once
#include "IInteractable.h"
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include "../Enums/ButtonEnum.cpp"

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
		class IButton : public Game::Models::IInteractable {
		protected:

			Game::Enums::ButtonEnum _type;
			/**
			*	Contains the height of the current window
			*/
			int _scene_height;
		public:
			IButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, Game::Enums::ButtonEnum type);
			/**
			*	Initializes the textures for an object
			*/
			virtual void initialize_textures() = 0;
			/**
			*	Checks if a mouse button is pressed in a given area
			*/
			void update(const Game::Events::InputEvent& object);
			/**
			*	Returns the type of the Button
			*/
			Game::Enums::ButtonEnum get_type();
			/**
			*	Action when the Button is pressed
			*/
			virtual void interact() = 0;
		};
	}
}