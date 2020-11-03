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
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;
			std::unique_ptr<Views::CreditsView> _credits_view;
			std::unique_ptr<Views::LevelView> _level_view;
			bool _open_window;
		public:
			WindowController();
			void update(const Game::Events::InputEvent& object);

			void create_window(int height, int width);
			void add_texture(const std::shared_ptr<Graphics::Models::Texture>& texture);
			void remove_texture(const std::shared_ptr<Graphics::Models::Texture>& texture);
			void update_window();
			void destroy_window();

			void set_level_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures);
		};
	}
}