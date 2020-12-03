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
		* \class Spike
		* \brief Class contains the methods and data of the Spike
		*/
		class Spike : public Models::Updatable {
		public:
			Spike(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center, Game::Enums::TypeEnum type);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			void set_angle(int speed);
			/**
			* \brief Updates the object when interacted with
			*/
			void update_object(Controllers::LevelController* ctrl = NULL);
		};
	}
}