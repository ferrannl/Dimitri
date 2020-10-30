#pragma once
#include "../Models/Window.h"
#include "../Models/Text.h"
#include <filesystem>

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

namespace Graphics {
	namespace Controllers
	{
		class GRAPHICS_API GraphicsController {
		private:
			std::shared_ptr<Models::Window> _window;

		public:
			GraphicsController();

			int create_window(const std::string title, const int height, const int width);
			void add_texture(const std::shared_ptr<Models::Texture>& texture);
			void remove_texture(const std::shared_ptr<Models::Texture>& texture);
			std::vector<std::shared_ptr<Models::Texture>> get_textures() const;

			void update_window();
			std::shared_ptr<Models::Window> get_window() const;
		};
	}
}