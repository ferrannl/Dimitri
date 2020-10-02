#pragma once
#include <sdl.h> 
#include <iostream>
#include "TextureFacade.h"
#include <vector>

namespace Facades{
	class __declspec(dllexport) WindowFacade
	{
	private:
		SDL_Window* _window;
		Facades::TextureFacade* _textureFacade;
		SDL_Surface* _background;
		SDL_Surface* _foreground;

		bool Init();
	public:
		WindowFacade() {
			_window = { nullptr };
			_textureFacade = { nullptr };
			_background = { nullptr };
			_foreground = { nullptr };
		}

		void create(const char* title, const int xpos, const int ypos, const int height, const int width);
		void create_sprites(std::vector<Models::Sprite*> sprites);
		void destroy();
		void update_sprites(std::vector<Models::Sprite*> sprites);
	};
}