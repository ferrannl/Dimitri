#pragma once

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else GRAPHICS_API __declspec(import)
#endif
#else
#define GRAPHICS_API
#endif

#include "../Models/Window.h"
#include <filesystem>

namespace Controllers
{
	class GraphicsController {
	private:
		std::shared_ptr<Models::Window> _window;

	public:
		GRAPHICS_API GraphicsController();

		GRAPHICS_API int create_window(const std::string title, const int height, const int width);
		GRAPHICS_API void add_sprites(std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites);
		GRAPHICS_API std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> get_sprites() const;

		GRAPHICS_API void update_window();
		GRAPHICS_API std::shared_ptr<Models::Window> get_window() const;
	};
}