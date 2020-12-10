#pragma once
#include "../Button.h"
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
			class ExitButton : public Game::Models::Button {
			public:
				ExitButton(const float x, const float y, const float z, const float height, const float width, const Enums::DirectionEnum state, const float scene_height, const Graphics::Models::Center center);

				/**
				* \brief Updates the object when interacted with
				*/
				void interact(Controllers::LevelController* ctrl = NULL);
			};
		}
	}
}
