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
		* \class Wall
		* \brief Class contains the data of the wall
		*/
		class Wall : public Models::Object {
		public:
			Wall(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();
		};
	}
}