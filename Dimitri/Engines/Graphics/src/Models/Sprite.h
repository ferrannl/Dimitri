#pragma once
#include "../Facades/TextureFacade.h"
#include "../Enums/FlipEnum.h"

namespace Models {
	class __declspec(dllexport) Sprite {
	
	private:
		float _x;
		float _y;
		float _z;
		float _width;
		float _height;
		float _angle;
		std::shared_ptr<Facades::TextureFacade> _facade;
		Enums::FlipEnum _flipstatus;
		const std::string _path;

	public:
		Sprite(const float x, const float y, const float z, const float height, const float width, const std::string path, const float angle, const Enums::FlipEnum flipstatus);

		float get_converted_y(float height) const;
		float get_x() const;
		float get_z() const;
		float get_y() const;
		float get_width() const;
		float get_height() const;
		float get_angle() const;
		std::shared_ptr<Facades::TextureFacade> get_texture_facade() const;
		Enums::FlipEnum get_flip_status() const;
		const std::string get_path() const;

		void set_x(const float x);
		void set_z(const float z);
		void set_y(const float y);
		void set_width(const float width);
		void set_height(const float height);
		void set_angle(const float angle);
		void set_flip_status(const Enums::FlipEnum flipstatus);
		void set_facade(const std::shared_ptr<Facades::TextureFacade> facade);
		void create_texture_facade();
	};
}