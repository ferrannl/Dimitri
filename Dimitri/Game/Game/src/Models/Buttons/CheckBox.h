#pragma once
#include "../Button.h"
#include "../Check.h"

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
			* \class CheckBox
			* \brief Class contains the methods for a functioning checkbox
			*/
			class CheckBox : public Game::Models::Button {
			private:
				/**
				* \brief Check callback function called when checkbox is clicked
				*/
				const std::shared_ptr<Check> _check;

				/**
				* \brief Check code to support multiple buttons in one screen
				*/
				int _check_code;

				/**
				* \brief Check sprite to make green V visible/invisible when pressed
				*/
				std::shared_ptr<Graphics::Models::Sprite> _check_sprite;
			public:
				CheckBox(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, const std::shared_ptr<Check> check, int check_code);

				/**
				* \brief Updates the object when interacted with
				*/
				void interact();
			};
		}
	}
}