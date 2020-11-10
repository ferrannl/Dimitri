#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Models/Level.h"
#include "../Events/InputEvent.h"
#include "../Controllers/WindowController.h"
#include <src\Models\Texture.h>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the controllers
	*/
	namespace Controllers {
		/**
		*	Contains the code to controle the level model
		*/
		class LevelController : public Utility::Interfaces::IObserver<Game::Events::InputEvent> {
		private:
			/**
			*	Level model
			*/
			std::shared_ptr<Game::Models::Level> _level;
			/**
			*	Simulation thread
			*/
			std::thread _simulation_thread;
			/**
			*	Keeps track of simulation thread state
			*/
			bool _running;
			/**
			*	WindowController to update camera potision
			\*/
			std::shared_ptr<Controllers::WindowController> _window_controller;
		public:
			LevelController(std::shared_ptr<Controllers::WindowController> window_controller);

			/**
			*	List of all textures in level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

			/**
			*	Update received from input controller
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			*	Returns level
			*/
			std::shared_ptr<Game::Models::Level> get_level() const;

			/**
			*	Start simulation
			*/
			void start();

			/**
			*	Stop simulation
			*/
			void stop();

			/**
			*	Simulate thread start
			*/
			void simulate();
		};
	}
}