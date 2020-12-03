#pragma once
#include "./Abstract/Interactable.h"
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"

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
		* \class Button
		* \brief Class contains the methods to use a button
		*/
		class Button : public Models::Interactable {
		protected:
			/**
			* \brief The height of the scene
			*/
			int _scene_height;
		public:
			Button(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, Graphics::Models::Center center);

			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Updates the object based on a fired event
			*/
			void update(const Game::Events::InputEvent& object);
			/**
			* \brief Updates the object when interacted with
			*/
			virtual void interact(Controllers::LevelController* ctrl = NULL) = 0;
		};
	}
}