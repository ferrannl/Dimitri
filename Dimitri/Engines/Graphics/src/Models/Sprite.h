#pragma once
#include <SDL.h>
#include "../Facades/TextureFacade.h"
#include "../Enums/FlipEnum.h"

namespace Models {
	class __declspec(dllexport) Sprite {
	private:
		int _x;
		int _y;
		int _z;
		int _width;
		int _height;
		float _angle;
		const char* _path;
		Facades::TextureFacade* _facade;
		Enums::FlipEnum _flipstatus;

	public:
		Sprite(const int x, const int y, const int z, const int height, const int width, const char* path, const float angle, const Enums::FlipEnum flipstatus)
			: _x{ x }, _y{ y }, _z{ z }, _height{ height }, _width{ width }, _path{ path }, _angle{ angle }, _flipstatus{ flipstatus } {
			_facade = { nullptr };
		}

		const int get_converted_y(int height);
		const int get_x();
		const int get_z();
		const int get_y();
		const int get_width();
		const int get_height();
		const float get_angle();
		Facades::TextureFacade* get_texture_facade();
		Enums::FlipEnum get_flip_status();

		const char* get_path();
		void set_x(const int x);
		void set_z(const int z);
		void set_y(const int y);
		void set_width(const int width);
		void set_height(const int height);
		void set_angle(const float angle);
		void set_flip_status(Enums::FlipEnum flipstatus);
		void set_facade(Facades::TextureFacade* facade);
		void create_texture_facade();
	};
}