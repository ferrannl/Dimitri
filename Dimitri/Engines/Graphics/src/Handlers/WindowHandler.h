#pragma once
#include <string> using namespace std
#include <SDL.h>
#include <stdio.h>
#include "../Models/Window.h"
#include <vector>

namespace Handlers 
{
	class WindowHandler 
	{
	private:
		Models::Window* _window;

		public: 
			WindowHandler() {
				_window = nullptr;
			}

			void create_window(const char* title, int xpos, int ypos, int height, int width);
			void add_sprites(std::vector<Models::Sprite*> sprites);
			std::vector<Models::Sprite*> get_sprites();

			void update_window();
			Models::Window* get_window();
	};
}