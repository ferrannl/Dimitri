#pragma once
#include "../Button.h"
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
			class AdvertisementButton : public Game::Models::Button {
			private:
				std::string _url;
				std::string _image_path;
				std::vector<std::string> images;
				Utility::Advertisement::advertisement ad;
				std::shared_ptr<Game::Controllers::WindowController> _window_controller;
			public:
				AdvertisementButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::shared_ptr<Game::Controllers::WindowController> window_controller);
				void initialize_textures();
				/**
				*	Action when the button is pressed
				*/
				void interact();
			};
		}
	}
}