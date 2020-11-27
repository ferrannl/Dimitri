#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include <src\Models\Texture.h>
#include "../Models/Buttons/StartButton.h"
#include "../Models/Buttons/ExitButton.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <tuple>
#include <memory>
#include "../Models/Buttons/AdvertisementButton.h"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the controllers
	*/
	namespace Controllers {
		/**
		*	Contains all code to interact with window engine and show images on screen
		*/
		class HomeController : public Utility::Interfaces::IObserver<Events::InputEvent>, std::enable_shared_from_this<HomeController> {
		private:
			std::vector<std::shared_ptr<Game::Models::Button>> _buttons;
			std::shared_ptr<Game::Controllers::WindowController> _window_controller;

			int _scene_height;
			int _scene_width;
		public:
			HomeController(int sceneheight, int scenewidth, std::shared_ptr<Game::Controllers::WindowController> window_controller);
			void load_buttons(std::shared_ptr<Managers::LevelManager> level_manager);
			void update(const Game::Events::InputEvent& object);
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;
			/**
			*	Initialize advertisements
			*/
			std::shared_ptr<Game::Models::Button> get_advertisement_button();
		};
	}
}
