#pragma once
#include <src\Controllers\GraphicsController.h>
#include "../Views/CreditsView.h"
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include "../Views/CreditsView.h"
#include "../Views/LevelView.h"

namespace Game {
	namespace Controllers {
		class WindowController : public Utility::Interfaces::IObserver<Game::Events::InputEvent> {
		private:
			/**
			*	Graphics Controller to interact with engine
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;
			/**
			*	Credits view to show credits
			*/
			std::unique_ptr<Views::CreditsView> _credits_view;
			/**
			*	Level view to show level
			*/
			std::unique_ptr<Views::LevelView> _level_view;
			/**
			*	Checks if there is already a rendered view
			*/
			bool _open_window;
		public:
			WindowController();
			/**
			*	Update from Game::Controllers::InputController
			*/
			void update(const Game::Events::InputEvent& object);
			
			/**
			*	Creates window
			*/
			void create_window(int height, int width);

			/**
			*	Adds Texture to window
			*/
			void add_texture(const std::shared_ptr<Graphics::Models::Texture>& texture);
			/**
			*	Removes texture from window
			*/
			void remove_texture(const std::shared_ptr<Graphics::Models::Texture>& texture);
			/**
			*	Refreshes window
			*/
			void update_window();
			/**
			*	Destroys window
			*/
			void destroy_window();

			/**
			*	Sets the textures for the level view
			*/
			void set_level_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures);
		};
	}
}