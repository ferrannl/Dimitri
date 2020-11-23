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
		* \class LightBeam
		* \brief Class contains the data of the light beam
		*/
		class LightBeam : public Models::Updatable {
		public:
			LightBeam(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Updates the object when interacted with
			*/
			void update(Controllers::LevelController* ctrl = NULL);
		};
	}
}