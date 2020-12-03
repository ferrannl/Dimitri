#pragma once
#include "Object.h"
#include "../../Enums/DirectionEnum.cpp"
#include "../../Enums/TypeEnum.cpp"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	namespace Controllers {
		class LevelController;
	}

	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {
		/**
		* \class Updatable
		* \brief Class contains the methods to be able to update the object
		*/
		class Updatable : public Object {
		protected:
			Game::Enums::TypeEnum _type;
		public:
			Updatable(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center, Game::Enums::TypeEnum type);

			/**
			* \brief update this object
			*/
			virtual void update_object(Controllers::LevelController* ctrl = NULL) = 0;

			virtual void set_speed(float speed);

			Game::Enums::TypeEnum get_type();
		};
	}
}