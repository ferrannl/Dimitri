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
		Models::Window* _window;
	public:
		GraphicsController() {
			_window = nullptr;
		}

		void create_window(const char* title, const int xpos, const int ypos, const int height, const int width);
		void add_sprites(std::vector<Models::Sprite*> sprites);
		std::vector<Models::Sprite*> get_sprites();

		void update_window();
		Models::Window* get_window();
	};
}