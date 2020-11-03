#pragma once
#include <memory>
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>

namespace Game {
	namespace Views {
		class CreditsView {
		private:
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
		public:
			bool is_open; // TODO: delete var when screen navigation is implemented
			CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);
			void init_textures();
			void open();
			void close();
		};
	}
}
