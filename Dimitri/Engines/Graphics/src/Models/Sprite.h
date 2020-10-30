#pragma once

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

#include "../Facades/TextureFacade.h"
#include "../Enums/FlipEnum.h"

namespace Graphics {
	/**
	* Namespace for all the models in the project
	*/
	namespace Models {
		/**
		* Holds the data the sprite needs to be rendered.
		*/
		class GRAPHICS_API Sprite {

		private:
			/**
			* The x coordinate the sprite is drawn to
			*/
			int _x;

			/**
			* The y coordinate the sprite is drawn to
			*/
			int _y;

			/**
			* The z coordinate the sprite is drawn to
			*/
			int _z;

			/**
			* The width of the sprite
			*/
			int _width;

			/**
			* The height of the sprite
			*/
			int _height;

			/**
			* The angle which the sprite is drawn with
			*/
			float _angle;

			/**
			* The facade that holds all references to SDL
			*/
			std::shared_ptr<Facades::TextureFacade> _facade;

			/**
			* The flip direction of the sprite
			*/
			Enums::FlipEnum _flipstatus;

			/**
			* The path to the image of the sprite
			*/
			const std::string _path;

		public:

			Sprite(const int x, const int y, const int z, const int height, const int width, const std::string path, const float angle, const Enums::FlipEnum flipstatus);

			/**
			* returns the y converted to be drawn from the perspective of bottom left
			*/
			int get_converted_y(int height) const;

			/**
			* returns the x coordinate
			*/
			int get_x() const;

			/**
			* returns the z coordinate
			*/
			int get_z() const;

			/**
			* returns the y coordinate
			*/
			int get_y() const;

			/**
			* returns the width
			*/
			int get_width() const;

			/**
			* returns the height
			*/
			int get_height() const;

			/**
			* returns the angle
			*/
			float get_angle() const;

			/**
			* returns the facade of the texture for the sprite
			*/
			std::shared_ptr<Facades::TextureFacade> get_texture_facade() const;

			/**
			* returns the flip direction
			*/
			Enums::FlipEnum get_flip_status() const;

			/**
			* returns the image path
			*/
			const std::string get_path() const;

			/**
			* sets the x coordinate
			*/
			void set_x(const int x);

			/**
			* sets the z coordinate
			*/
			void set_z(const int z);

			/**
			* sets the y coordinate
			*/
			void set_y(const int y);

			/**
			* sets the width
			*/
			void set_width(const int width);

			/**
			* sets the height
			*/
			void set_height(const int height);

			/**
			* sets the angle
			*/
			void set_angle(const float angle);

			/**
			* sets the flip direction
			*/
			void set_flip_status(const Enums::FlipEnum flipstatus);

			/**
			* sets the facade containing the references to sdl
			*/
			void set_facade(const std::shared_ptr<Facades::TextureFacade> facade);

			/**
			* creates the texture facade
			*/
			void create_texture_facade();
		};
	}
}