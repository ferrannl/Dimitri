#pragma once
#include "../Button.h"
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
			class AdvertisementButton : public Game::Models::Button {
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
				AdvertisementButton(const float x, const float y, const float z, const float height, const float width, const Enums::DirectionEnum state, const float scene_height, const std::shared_ptr<Game::Controllers::WindowController> window_controller, const Graphics::Models::Center center);
			
				/**
				* \brief Initializes the textures for an object
				*/
				void initialize_textures()override;

				/**
				* \brief Updates the object when interacted with
				*/
				void interact(Controllers::LevelController* ctrl = NULL);
			};
		}
	}
}