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
				StartButton(const float x, const float y, const float z, const float height, const float width, const Enums::DirectionEnum state, const float scene_height, const std::shared_ptr<Managers::LevelManager> level_manager, const Graphics::Models::Center center);

				/**
				* \brief Action when the button is pressed
				*/
				void interact(Controllers::LevelController* ctrl = NULL);
			};
		}
	}
}
