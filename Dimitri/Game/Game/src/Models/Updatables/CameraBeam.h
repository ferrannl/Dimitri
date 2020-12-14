#pragma once
#include "../Abstract/Updatable.h"

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
		* \class CameraBeam
		* \brief Class contains the data of the CameraBeam
		*/
		class CameraBeam : public Models::Updatable {
		private:

			/**
			* \brief Bounds for the camerabeam location
			*/
			float _bounds;
		public:
			CameraBeam(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Updates the object when interacted with
			*/
			void update_object(Controllers::LevelController* ctrl = NULL);

			/**
			* \brief Sets the bounds of the camera beam rotation
			*/
			void set_bounds(float bounds);
		};
	}
}