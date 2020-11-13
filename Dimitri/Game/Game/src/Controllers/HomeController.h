#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include <src\Models\Texture.h>
#include <chrono>
#include <thread>
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
		public:
			void update(const Game::Events::InputEvent& object);
		};
	}
}
