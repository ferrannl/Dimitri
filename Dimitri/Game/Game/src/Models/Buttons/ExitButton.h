#pragma once
#include "../IButton.h"
#include <cstdlib>

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
		* \namespace Game::Models::Buttons
		* \brief Namespace for the buttons in the game
		*/
		namespace Buttons {
			/**
			* \class ExitButton
			* \brief Class contains the methods close the game
			*/
			class ExitButton : public Game::Models::IButton {
			private:
			public:
				ExitButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height);

				/**
				* \brief Updates the object when interacted with
				*/
				void interact();

				void initialize_textures();

			};
		}
	}
}
