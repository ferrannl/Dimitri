#pragma once
#include <string> using namespace std
#include <SDL.h>
#include <stdio.h>
#include "../Models/Window.h"
#include <vector>
#include <filesystem>

namespace Controllers
{
	class __declspec(dllexport) GraphicsController {
	private:
		std::shared_ptr<Models::Window> _window;

	public:
		GraphicsController() {
			_window = nullptr;
		}

		void create_window(const std::string title, const int height, const int width);
		void add_sprites(std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites);
		std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> get_sprites() const;

		void update_window();
		std::shared_ptr<Models::Window> get_window() const;
	};
}