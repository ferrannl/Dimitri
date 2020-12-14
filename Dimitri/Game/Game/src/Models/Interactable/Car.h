#pragma once
#include "../Abstract/Interactable.h"

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
		* \class Car
		* \brief Class contains the methods and data of the Car
		*/
<<<<<<< HEAD:Dimitri/Game/Game/src/Models/Interactable/Switch.h
		class Switch : public Models::Interactable {
		private:
			int _switch_x;
		public:
			Switch(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center);
=======
		class Car : public Models::Interactable {
		public:
			Car(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center);
>>>>>>> develop:Dimitri/Game/Game/src/Models/Interactable/Car.h

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();
			/**
			* \brief Updates the object when interacted with
			*/
			void interact(Controllers::LevelController* ctrl = NULL);
<<<<<<< HEAD:Dimitri/Game/Game/src/Models/Interactable/Switch.h
			void set_light(const int x);
=======
>>>>>>> develop:Dimitri/Game/Game/src/Models/Interactable/Car.h
		};
	}
}