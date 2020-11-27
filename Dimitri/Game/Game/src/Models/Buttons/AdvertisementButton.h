#pragma once
#include "../Button.h"
#include <cstdlib>
#include <src/Helpers/BasePathHelper.h>
#include <src/Advertisement/advertisement.h>
#include <string>

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
			public:
				AdvertisementButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::string url, std::string image_path);
				void initialize_textures();
				/**
				*	Action when the button is pressed
				*/
				void interact();
			};
		}
	}
}