#pragma once
#include <SDL.h>
#include <string>
#include "../Facades/WindowFacade.h"
#include <vector>
#include <memory>

namespace Models {
	class __declspec(dllexport) Window {
	private:
		int _height;
		int _width;
		std::string _title;
		std::unique_ptr<Facades::WindowFacade> _facade;
		std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> _sprites;

	public:
		Window(const std::string title, const int height, const int width);
			
		void create();
		void update();
		void destroy();
		void set_sprites(const std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> sprites);
		const std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> get_sprites();
		const int get_height();
		const int get_width();
		const std::string get_title();
	};
}
