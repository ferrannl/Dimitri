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
		private:
			float area(int x1, int y1, int x2, int y2, int x3, int y3);
		public:
			LightBeam(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Updates the object when interacted with
			*/
			void update_object(Controllers::LevelController* ctrl = NULL);
			bool checkcollision(std::shared_ptr<Models::Object> object);
		};
	}
}