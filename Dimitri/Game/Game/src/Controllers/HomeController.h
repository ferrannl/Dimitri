#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include <src\Models\Texture.h>
#include "..\Models\Button.h"
#include "../Models/Buttons/StartButton.h"
#include "../Models/Buttons/ExitButton.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <tuple>
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
		class HomeController : public Utility::Interfaces::IObserver<Events::InputEvent> {
		private:
			std::vector<std::shared_ptr<Game::Models::Button>> _buttons;
			void init_buttons();
			int _scene_height;
			int _scene_width;
		public:
			HomeController(int sceneheight, int shenewidth);
			void update(const Game::Events::InputEvent& object);
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

		};
	}
}
