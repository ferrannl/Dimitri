#pragma once
#include <SDL.h>
#include "../Facades/TextureFacade.h"
#include "../Enums/FlipEnum.h"
#include <memory>

namespace Models {
	class __declspec(dllexport) Sprite {
	
	private:
		int _x;
		int _y;
		int _z;
		int _width;
		int _height;
		float _angle;
		std::string _path;
		std::shared_ptr<Facades::TextureFacade> _facade;
		Enums::FlipEnum _flipstatus;

	public:
		Sprite(const int x, const int y, const int z, const int height, const int width, const std::string path, const float angle, const Enums::FlipEnum flipstatus);

		const int get_converted_y(int height);
		const int get_x();
		const int get_z();
		const int get_y();
		const int get_width();
		const int get_height();
		const float get_angle();
		std::shared_ptr<Facades::TextureFacade> get_texture_facade();
		Enums::FlipEnum get_flip_status();
		const std::string get_path();

		void set_x(const int x);
		void set_z(const int z);
		void set_y(const int y);
		void set_width(const int width);
		void set_height(const int height);
		void set_angle(const float angle);
		void set_flip_status(Enums::FlipEnum flipstatus);
		void set_facade(std::shared_ptr<Facades::TextureFacade> facade);
		void create_texture_facade();
	};
}