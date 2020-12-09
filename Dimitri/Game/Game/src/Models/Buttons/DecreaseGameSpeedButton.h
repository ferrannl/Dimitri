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
			* \class StartButton
			* \brief Class contains the methods start a level
			*/
			class DecreaseGameSpeedButton : public Game::Models::Button {
			public:
				DecreaseGameSpeedButton(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, Graphics::Models::Center center);

				/**
				* \brief Updates the object when interacted with
				*/
				void interact(Controllers::LevelController* ctrl = NULL);
			};
		}
	}
}