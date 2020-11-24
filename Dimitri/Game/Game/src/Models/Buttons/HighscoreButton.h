#pragma once
#include "../Button.h"

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
		* \namespace Game::Buttons
		* \brief Namespace for the buttons in the game
		*/
		namespace Buttons {
			/**
			* \class Highscorebutton
			* \brief Class contains the methods to load the HighscoreView
			*/
			class HighscoreButton : public Game::Models::Button {
			private:
			public:
				HighscoreButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height);

				/**
				* \brief Updates the object when interacted with
				*/
				void interact();
			}
		}
	}
}
