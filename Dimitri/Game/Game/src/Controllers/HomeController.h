#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include <src\Models\Texture.h>
#include "../Models/Buttons/StartButton.h"
#include "../Models/Buttons/ExitButton.h"
#include "../Controllers/AudioController.h"
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
		* \class HomeController
		* \brief Class contains the methods to interact with window engine and show images on screen
		*/
		class HomeController : public Utility::Interfaces::IObserver<Events::InputEvent>, std::enable_shared_from_this<HomeController> {
		private:
			/**
			* \brief A list of the Buttons
			*/
			std::vector<std::shared_ptr<Game::Models::Button>> _buttons;
			/**
			* \brief An instance of the Audio Controller
			*/
			std::shared_ptr<Game::Controllers::AudioController> _audio_controller;
			int _scene_height;

			/**
			* \brief The width of the scene
			*/
			int _scene_width;
		public:
			HomeController(int sceneheight, int scenewidth, std::shared_ptr<Game::Controllers::AudioController> audio_controller);
			/**
			* \brief Loads the Buttons
			*/
			void load_buttons(std::shared_ptr<Managers::LevelManager> level_manager);

			/**
			* \brief Updates the Buttons
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			* \brief Returns the Textures from the Buttons
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

		};
	}
}
