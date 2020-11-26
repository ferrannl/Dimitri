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
			* \brief Class contains the methods close the game
			*/
			class CheckBox : public Game::Models::Button {
			private:
				const std::shared_ptr<Check> _check;
				int _check_code;
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