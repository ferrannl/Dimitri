#pragma once
#include "../Models/Sprite.h"
#include "../Models/Text.h"
#include "../Adapters/FlipEnumAdapter.h"
namespace Graphics {
	namespace Facades {
		class __declspec(dllexport) WindowFacade {
		private:
			std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
			std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;
			Adapters::FlipEnumAdapter _flip_enum_adapter;
		public:
			WindowFacade();

			int create_renderer();
			int create_window(const std::string title, const int height, const int width);
			void create_texture(const std::shared_ptr<Models::Texture>& texture, const std::shared_ptr<Models::Texture>& texture_equal_path);
			void destroy();
			void update_window(const std::vector<std::shared_ptr<Models::Texture>> textures);
		};
	}
}