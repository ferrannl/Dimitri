#pragma once
#include <string>
#include <memory>
#include "../Enums/FlipEnum.h"
#include "../Facades/TextureFacade.h"



#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

namespace Graphics {
	/**
	* Namespace for all the models in the project
	*/
	namespace Models {
		/**
		* Holds the data the texture needs to be rendered.
		*/
		class GRAPHICS_API Texture {
		private:
			/**
			* The x coordinate the texture is drawn to
			*/
			int _x;

			/**
			* The y coordinate the texture is drawn to
			*/
			int _y;

			/**
			* The z coordinate the texture is drawn to
			*/
			int _z;

			/**
			* The width of the texture
			*/
			int _width;

			/**
			* The height of the texture
			*/
			int _height;

			/**
			* The angle which the texture is drawn with
			*/
			float _angle;

			/**
			* Visibility of texture
			*/
			bool _visible;

			/**
			* The path of the texture
			*/
			std::string _path;
		protected:
			/**
			* The flip direction of the texture
			*/
			Enums::FlipEnum _flipstatus;

			/**
			* The facade that holds all references to SDL
			*/
			std::shared_ptr<Facades::TextureFacade> _facade;
		public:
			Texture(const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path);

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
			* returns the z coordinate
			*/
			int get_y() const;

			/**
			* returns the z coordinate
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
			* returns the image path
			*/
			std::string get_path() const;

			/**
			* returns the flip direction
			*/
			Enums::FlipEnum get_flip_status() const;

			/**
			* returns the visibility
			*/
			bool get_visible() const;

			/**
			* returns the facade of the texture for the sprite
			*/
			std::shared_ptr<Facades::TextureFacade> get_texture_facade() const;

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
			* sets the visibility
			*/
			void set_visible(const bool visibility);

			/**
			* sets the facade containing the references to sdl
			*/
			void set_facade(const std::shared_ptr<Facades::TextureFacade>& facade);

			/**
			* creates the texture facade
			*/
			virtual void create_texture_facade() = 0;

			/**
			* Checks if this texure matches the given texture
			*/
			virtual bool matches(const std::shared_ptr<Models::Texture>& texture) const = 0;
		};
	}
}