#pragma once

#ifdef WIN32
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else GRAPHICS_API __declspec(import)
#endif
#else
#define GRAPHICS_API
#endif

#include "../Facades/TextureFacade.h"
#include "../Enums/FlipEnum.h"

namespace Models {
class Sprite {
	
	private:
		int _x;
		int _y;
		int _z;
		int _width;
		int _height;
		float _angle;
		std::shared_ptr<Facades::TextureFacade> _facade;
		Enums::FlipEnum _flipstatus;
		const std::string _path;

	public:
		GRAPHICS_API Sprite(const int x, const int y, const int z, const int height, const int width, const std::string path, const float angle, const Enums::FlipEnum flipstatus);

		GRAPHICS_API  int get_converted_y(int height) const;
		GRAPHICS_API  int get_x() const;
		GRAPHICS_API  int get_z() const;
		GRAPHICS_API  int get_y() const;
		GRAPHICS_API  int get_width() const;
		GRAPHICS_API  int get_height() const;
		GRAPHICS_API  float get_angle() const;
		std::shared_ptr<Facades::TextureFacade> get_texture_facade() const;
		GRAPHICS_API  Enums::FlipEnum get_flip_status() const;
		GRAPHICS_API  const std::string get_path() const;

		GRAPHICS_API void set_x(const int x);
		GRAPHICS_API void set_z(const int z);
		GRAPHICS_API void set_y(const int y);
		GRAPHICS_API void set_width(const int width);
		GRAPHICS_API void set_height(const int height);
		GRAPHICS_API void set_angle(const float angle);
		GRAPHICS_API void set_flip_status(const Enums::FlipEnum flipstatus);
		void set_facade(const std::shared_ptr<Facades::TextureFacade> facade);
		void create_texture_facade();
	};
}