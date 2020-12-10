#pragma once
#include "../Events/InputEvent.h"
#include <src/Models/Texture.h>
#include "../Enums/ButtonEnum.h"

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
		class Button {
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
			* \brief The identifier of the button
			*/
			Enums::ButtonEnum _identifier;

			/**
			* \brief The texture of the button
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
		public:
			Button(float x, float y, float height, float width, const std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, Enums::ButtonEnum identifier);

			/**
			* \brief Checks if the button is clicked
			*/
			bool is_clicked(Game::Events::InputEvent object);

			/**
			* \brief Returns the texture
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

			/**
			* \brief Returns the x coordinate of the button
			*/
			float get_x() const;

			/**
			* \brief Returns the y coordinate of the button
			*/
			float get_y() const;

			/**
			* \brief Sets the x coordinate of the button
			*/
			void set_x(float x);

			/**
			* \brief Sets the y coordinate of the button
			*/
			void set_y(float y);

			/**
			* \brief Returns the identifier of the button
			*/
			Enums::ButtonEnum get_identifier() const;
		};
	}
}