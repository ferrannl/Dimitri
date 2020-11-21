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
		* \class LightBeam
		* \brief Class contains the data of the light beam
		*/
		class LightBeam : public Game::Models::IObject {
		public:
			LightBeam(int x, int y, int z, int height, int width, Game::Enums::StateEnum state);

			/**
			* \brief Initializes textures
			*/
			void initialize_textures();
		};
	}
}