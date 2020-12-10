#pragma once
#include "../Button.h"
#include "../../Managers/LevelManager.h"

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
		* \namespace Game::Buttons
		* \brief Namespace for the buttons in the game
		*/
		namespace Buttons {
			/**
			* \class StartButton
			* \brief Class contains the methods start a level
			*/
			class StartButton : public Game::Models::Button {
			private:
				/**
				* \brief An instance of the Level Manager
				*/
				std::shared_ptr<Game::Managers::LevelManager> _level_manager;
			public:
				StartButton(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, std::shared_ptr<Managers::LevelManager> level_manager, Graphics::Models::Center center);

				/**
				* \brief Action when the button is pressed
				*/
				void interact(Controllers::LevelController* ctrl = NULL);
			};
		}
	}
}
