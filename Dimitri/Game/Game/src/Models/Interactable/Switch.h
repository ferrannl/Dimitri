#pragma once
#include "../Abstract/Interactable.h"

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
		* \class Switch
		* \brief Class contains the methods and data of the Switch
		*/
		class Switch : public Models::Interactable {
		private:
			/**
			* \brief The x coordinate of the beam
			*/
			float _switch_x;
		public:
			Switch(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Updates the object when interacted with
			*/
			void interact(Controllers::LevelController* ctrl = NULL);

			/**
			* \brief Sets the x coordinate of the beam location
			*/
			void set_light(const float x);
		};
	}
}