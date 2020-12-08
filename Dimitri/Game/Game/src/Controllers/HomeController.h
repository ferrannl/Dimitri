#pragma once
#include <chrono>
#include <thread>
#include <iostream>
#include <tuple>
#include <memory>
#include <src\Interfaces\IObserver.h>
#include <src\Models\Texture.h>
#include <src/Models/Sprite.h>
#include <src/Models/Text.h>
#include "../Events/InputEvent.h"
#include "../Controllers/AudioController.h"
#include "../Models/Button.h"

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
			std::vector<std::unique_ptr<Game::Models::Button>> _buttons;

			/**
			* \brief An instance of the Audio Controller
			*/
			std::shared_ptr<Game::Controllers::AudioController> _audio_controller;

			/**
			* \brief The height of the scene
			*/
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
			void load_buttons();

			/**
			* \brief Calls on click event on the buttons if clicked
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			* \brief Returns the Textures from the Buttons
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

		};
	}
}
