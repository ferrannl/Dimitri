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
			void create_window(const char* title, int xpos, int ypos, int height, int width);
			void add_sprites(std::vector<Models::Sprite*> sprites);
			std::vector<Models::Sprite*> get_sprites();

			void update_window();
			Models::Window* get_window();


	private:
		//Starts up SDL and creates window
		bool init(const char* title, int xpos, int ypos, int height, int width);

		//Frees media and shuts down SDL
		void close();

		//The window we'll be rendering to
		SDL_Window* gWindow = NULL;

		//The surface contained by the window
		SDL_Surface* gScreenSurface = NULL;

		//The image we will load and show on the screen
		SDL_Surface* gHelloWorld = NULL;
	};
}