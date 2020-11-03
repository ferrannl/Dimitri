#pragma once
#include <vector>
#include <memory>
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

namespace Game {
	namespace Views {
		class LevelView {
		private:
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
			std::thread draw_thread;
		public:
			bool is_open; // TODO: delete var when screen navigation is implemented
			LevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);
			void init_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures);
			void open();
			void close();
			void draw();
		};
	}
}