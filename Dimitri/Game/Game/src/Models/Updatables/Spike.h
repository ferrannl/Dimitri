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
		* \class Switch
		* \brief Class contains the methods and data of the Switch
		*/
		class Spike : public Models::Updatable {
		public:
			Spike(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center);

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