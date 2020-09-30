#pragma once
#include <string> using namespace std
#include <SDL.h>

namespace Models 
{
	class Sprite {
	private:
		int _x;
		int _y;
		int _width;
		int _height;
		std::string _path;
		SDL_Texture* _texture;
	public:
		Sprite(int x, int y, int height, int width, std::string path) : _x{ x }, _y{ y }, _height{ height }, _width{ width }, _path{ path } {
			_texture = NULL;
		}

		int get_x();
		int get_y();
		int get_width();
		int get_height();
		void set_x(int x);
		void set_y(int y);
		void set_width(int width);
		void set_height(int height);
		std::string get_path();
		void add_texture(SDL_Texture* texture);
		SDL_Texture* get_texture();
	};
}