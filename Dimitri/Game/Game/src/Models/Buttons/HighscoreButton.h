#pragma once
#include "../Button.h"
#include "../../Managers/HighscoreManager.h"


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
			* \class Highscorebutton
			* \brief Class contains the methods to load the HighscoreView
			*/
			class HighscoreButton : public Game::Models::Button {
			private:
				/**
				* \brief An instance of the Highscore Manager
				*/
				std::shared_ptr<Game::Managers::HighscoreManager> _highscore_manager;
			public:
				HighscoreButton(int x, int y, int z, int height, int width, Enums::DirectionEnum state, int scene_height, std::shared_ptr<Game::Managers::HighscoreManager> highscore_manager, Graphics::Models::Center center);

				/**
				* \brief Updates the object when interacted with
				*/
				void interact(Controllers::LevelController* ctrl = NULL);
			};
		}
	}
}
