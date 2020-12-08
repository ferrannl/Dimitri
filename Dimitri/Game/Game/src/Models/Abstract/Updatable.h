#pragma once
#include "Object.h"
#include "../../Enums/DirectionEnum.h"
#include "../../Enums/TypeEnum.h"

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
		public:
			Updatable(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center);

			/**
			* \brief update this object
			*/
			virtual void update_object(Controllers::LevelController* ctrl = NULL) = 0;

			/**
			* \brief Sets the speed
			*/
			virtual void set_speed(float speed);
		};
	}
}
