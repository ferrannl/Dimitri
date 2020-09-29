#pragma once
#include <string> using namespace std
#include <SDL.h>
#include <stdio.h>
#include "../Models/Window.h"

namespace Handlers 
{
	class WindowHandler 
	{
		public: 
			void CreateWindow(const char* title, int xpos, int ypos, int height, int width);
			void DeleteWindow();
			Models::Window GetWindow();


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