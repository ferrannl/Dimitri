#pragma once
#include "IInteractable.h"
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include "../Enums/ButtonEnum.cpp"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Models
	* \brief Namespace for the Models
	*/
	namespace Models {
		/**
		* \class IButton
		* \brief Contains all code necessary for the button object
		*/
		class Button : public Game::Models::IInteractable {
		protected:

			Game::Enums::ButtonEnum _type;
			/**
			* \brief Contains the height of the current window
			*/
			int _scene_height;
		public:
			Button(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, Game::Enums::ButtonEnum type);
			/**
			* \brief Initializes the textures for an object
			*/
			virtual void initialize_textures() = 0;
			/**
			* \brief Checks if a mouse button is pressed in a given area
			*/
			void update(const Game::Events::InputEvent& object);
			/**
			* \brief Returns the type of the Button
			*/
			Game::Enums::ButtonEnum get_type();
			/**
			* \brief Action when the Button is pressed
			*/
			virtual void interact() = 0;
		};
	}
}