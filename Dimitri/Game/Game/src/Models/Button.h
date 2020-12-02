#pragma once
#include "./Abstract/Interactable.h"
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include "../Mediators/BaseComponent.h"

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
		class Button : public Game::Models::Interactable, public Mediators::BaseComponent {
		protected:
			/**
			* \brief The height of the scene
			*/
			int _scene_height;
		public:
			Button(int x, int y, int z, int height, int width, Enums::DirectionEnum state, int scene_height, Graphics::Models::Center center, const std::string& identifier);

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