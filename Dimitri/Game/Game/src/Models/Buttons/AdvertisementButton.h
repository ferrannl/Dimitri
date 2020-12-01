#pragma once
#include "../IButton.h"
#include <src/Advertisement/Advertisement.h>
#include <iostream>
#include "../../Controllers/WindowController.h"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Models
	*/
	namespace Models {
		/**
		*	Namespace for the Buttons
		*/
		namespace Buttons {
			class AdvertisementButton : public Game::Models::IButton {
			private:
				/**
				*	Contains the path of the advertisement image
				*/
				std::string _image_path;
				/**
				*	Contains all paths of the images
				*/
				std::vector<std::string> images;
				/**
				*	Instance of adveritsement, which loads the images
				*/
				Utility::Advertisement::advertisement ad;
				/**
				*	Instance of the window controller
				*/
				std::shared_ptr<Game::Controllers::WindowController> _window_controller;
			public:
				AdvertisementButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::shared_ptr<Game::Controllers::WindowController> window_controller);
				/**
				*	Initializes the textures of an object
				*/
				void initialize_textures();
				/**
				*	Action when the button is pressed
				*/
				void interact();
			};
		}
	}
}