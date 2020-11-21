#pragma once
#pragma once
#include "IObject.h"

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
		* \class Lamp
		* \brief Class contains the data of the Lamp
		*/
		class Lamp : public Game::Models::IObject {
		public:
			Lamp(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);

			/**
			* \brief Initializes textures
			*/
			void initialize_textures();
		};
	}
}