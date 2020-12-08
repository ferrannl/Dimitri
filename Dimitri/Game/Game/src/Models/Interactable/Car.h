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
		* \class Car
		* \brief Class contains the methods and data of the Car
		*/
		class Car : public Models::Interactable {
		public:
			Car(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Updates the object when interacted with
			*/
			void interact(Controllers::LevelController* ctrl = NULL);
		};
	}
}