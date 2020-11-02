#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Models/Level.h"
#include "../Events/InputEvent.h"
#include <src\Models\Texture.h>
namespace Game {
	namespace Controllers {
		class LevelController : public Utility::Interfaces::IObserver<Game::Models::InputEvent> {
		private:
			std::shared_ptr<Game::Models::Level> _level;
		public:
			LevelController();

			/**
			*	List of all textures in level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures();

			/**
			*	Update received from input controller
			*/
			void update(const Game::Models::InputEvent& object);

			std::shared_ptr<Game::Models::Level> get_level();
		};
	}
}