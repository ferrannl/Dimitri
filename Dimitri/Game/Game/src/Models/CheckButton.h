#pragma once
#include "Button.h"
#include <src\Models\Texture.h>

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
		* \class CheckBox
		* \brief Class contains the methods for a functioning checkbox
		*/
		class CheckButton : public Game::Models::Button {
		private:
			/**
			* \brief Check sprite to make green V visible/invisible when pressed
			*/
			std::shared_ptr<Graphics::Models::Texture> _check_sprite;
		public:
			CheckButton(float x, float y, float height, float width, const std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, Enums::ButtonEnum identifier);

			/**
			* \brief Checks if the button is clicked
			*/
			bool is_clicked(Game::Events::InputEvent object) override;
		};
	}
}
