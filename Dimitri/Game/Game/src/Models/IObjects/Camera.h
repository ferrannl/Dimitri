#pragma once
#include "../Abstract/Object.h"

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
		* \class Camera
		* \brief Class contains the data of the Camera
		*/
		class Camera : public Models::Object {
		public:
			Camera(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();
		};
	}
}