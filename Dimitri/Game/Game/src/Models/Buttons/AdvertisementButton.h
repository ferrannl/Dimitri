#pragma once
#include "../IButton.h"
#include <src/Advertisement/Advertisement.h>
#include <iostream>
#include "../../Controllers/WindowController.h"

/**
*	/namespace Game
*	/brief Namespace for the game
*/
namespace Game {
	/**		
	*	/namespace Game::Models
	*	/brief Namespace for the Models
	*/
	namespace Models {
		/**
		*	/namespace Game::Models::Buttons
		*	/brief Namespace for the Buttons
		*/
		namespace Buttons {
			/**
			* \class AdvertisementButton
			* \brief Class contains the methods for showing an advertisement
			*/
			class AdvertisementButton : public Game::Models::IButton {
			private:
				/**
				*	/brief Contains the path of the advertisement image
				*/
				std::string _image_path;
				/**
				*	/brief Contains all paths of the images
				*/
				std::vector<std::string> images;
				/**
				*	/brief Instance of adveritsement, which loads the images
				*/
				Utility::Advertisement::advertisement ad;
				/**
				*	/brief Instance of the window controller
				*/
				std::shared_ptr<Game::Controllers::WindowController> _window_controller;
			public:
				AdvertisementButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::shared_ptr<Game::Controllers::WindowController> window_controller);
				/**
				*	/brief Initializes the textures of an object
				*/
				void initialize_textures();
				/**
				*	/brief Action when the button is pressed
				*/
				void interact();
			};
		}
	}
}