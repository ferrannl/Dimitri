#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Models/Level.h"
#include "../Events/InputEvent.h"
#include <src\Models\Texture.h>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

namespace Game {
	namespace Controllers {
		class LevelController : public Utility::Interfaces::IObserver<Game::Events::InputEvent> {
		private:
			std::shared_ptr<Game::Models::Level> _level;
			std::thread _simulation_thread;
			bool _running;
		public:
			LevelController();

			/**
			*	List of all textures in level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures();

			/**
			*	Update received from input controller
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			*	Returns level
			*/
			std::shared_ptr<Game::Models::Level> get_level();

			void start();

			void stop();

			/**
			*	Simulate thread start
			*/
			void simulate();
		};
	}
}