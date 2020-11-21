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

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
	*/
	namespace Controllers {
		/**
		*	Contains all code to interact with window engine and show images on screen
		*/
		class HomeController : public Utility::Interfaces::IObserver<Events::InputEvent>, std::enable_shared_from_this<HomeController> {
		private:
			std::vector<std::shared_ptr<Game::Models::Button>> _buttons;

			int _scene_height;
			int _scene_width;
		public:
			HomeController(int sceneheight, int scenewidth);
			void load_buttons(std::shared_ptr<Managers::LevelManager> level_manager);
			void update(const Game::Events::InputEvent& object);
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

		};
	}
}
