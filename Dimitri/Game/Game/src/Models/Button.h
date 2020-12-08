#pragma once
#include "../Events/InputEvent.h"
#include "../Mediators/BaseComponent.h"
#include <src/Models/Texture.h>

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
		* \class Button
		* \brief Class contains the methods to use a button
		*/
		class Button : public Mediators::BaseComponent {
		private:
			/**
			* \brief The x coordinate of the button
			*/
			float _x;

			/**
			* \brief The y coordinate of the button
			*/
			float _y;

			/**
			* \brief The heigh of the button
			*/
			float _height;

			/**
			* \brief The width of the button
			*/
			float _width;

			/**
			* \brief The texture of the button
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
		public:
			Button(float x, float y, float height, float width, const std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, const std::string& identifier);

			/**
			* \brief Checks if the button is clicked
			*/
			bool is_clicked(Game::Events::InputEvent object);

			/**
			* \brief Fires the button event
			*/
			void on_click(Game::Events::InputEvent object);

			/**
			* \brief Returns the texture
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;
		};
	}
}