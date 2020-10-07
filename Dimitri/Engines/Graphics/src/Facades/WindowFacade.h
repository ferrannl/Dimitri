#pragma once
#include <sdl.h> 
#include "../Models/Sprite.h"
#include <iostream>
#include "TextureFacade.h"
#include <vector>

namespace Facades {
	class __declspec(dllexport) WindowFacade {
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;

		bool Init();
		Facades::TextureFacade* get_if_exists(std::vector<Models::Sprite*> sprites, const char* path);
	public:
		WindowFacade() {
			_window = { nullptr };
			_renderer = { nullptr };
		}

		void create_renderer();
		void create_window(const char* title, const int xpos, const int ypos, const int height, const int width);
		void create_sprites(std::vector<Models::Sprite*> sprites);
		void destroy();
		void update_window(std::vector<Models::Sprite*> sprites);
	};
}