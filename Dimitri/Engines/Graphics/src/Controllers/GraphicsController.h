#pragma once
#include <string> using namespace std
#include <SDL.h>
#include <stdio.h>
#include "../Models/Window.h"
#include <vector>
#include <filesystem>

namespace Controllers 
{
	class GraphicsController
	{
	private:
		Models::Window* _window;

		public: 
			GraphicsController() {
				_window = nullptr;
			}

			const char* concat_char(const char* char1, const char* char2);
			void create_window(const char* title, const int xpos, const int ypos, const int height, const int width);
			void add_sprites(std::vector<Models::Sprite*> sprites);
			std::vector<Models::Sprite*> get_sprites();

			void update_window();
			Models::Window* get_window();
	};
}