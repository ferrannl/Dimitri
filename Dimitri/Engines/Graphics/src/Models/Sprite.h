#pragma once
#include <SDL.h>
#include "Texture.h"

namespace Models 
{
	class Sprite {
	private:
		int _x;
		int _y;
		int _z;
		int _width;
		int _height;
		const char* _path;
		Models::Texture* _texture;

	public:
		Sprite(const int x, const int y, const int z, const int height, const int width, const char* path)
			: _x{ x }, _y{ y }, _z{ z }, _height{ height }, _width{ width }, _path{ path } {
			_texture = nullptr;
		}

		const int get_converted_y(int height);
		const int get_x();
		const int get_z();
		const int get_y();
		const int get_width();
		const int get_height();
		Models::Texture* get_texture();

		const char* get_path();
		void set_x(const int x);
		void set_z(const int z);
		void set_y(const int y);
		void set_width(const int width);
		void set_height(const int height);
		void set_texture(Models::Texture* texture);
	};
}