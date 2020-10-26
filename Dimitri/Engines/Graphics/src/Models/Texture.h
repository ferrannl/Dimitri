#pragma once
#include "../Facades/TextureFacade.h"
#include "../Enums/FlipEnum.h"

namespace Graphics {
	namespace Models {
		class __declspec(dllexport) Texture {
		private:
			int _x;
			int _y;
			int _z;
			int _width;
			int _height;
			float _angle;
			std::string _path;
			std::shared_ptr<Facades::TextureFacade> _facade;
		protected:
			Enums::FlipEnum _flipstatus;
		public:
			Texture(const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path);

			int get_converted_y(int height) const;
			int get_x() const;
			int get_z() const;
			int get_y() const;
			int get_width() const;
			int get_height() const;
			float get_angle() const;
			std::string get_path() const;
			Enums::FlipEnum get_flip_status() const;
			std::shared_ptr<Facades::TextureFacade> get_texture_facade() const;

			void set_x(const int x);
			void set_z(const int z);
			void set_y(const int y);
			void set_width(const int width);
			void set_height(const int height);
			void set_angle(const float angle);
			void set_flip_status(const Enums::FlipEnum flipstatus);
			void set_facade(const std::shared_ptr<Facades::TextureFacade> facade);
			void create_texture_facade();
		};
	}
}