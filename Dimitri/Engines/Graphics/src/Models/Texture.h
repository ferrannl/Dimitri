#pragma once
#include <string>
#include <memory>
#include "../Enums/FlipEnum.h"
#include "../Facades/TextureFacade.h"
#include "Center.h"

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

/**
* \namespace Graphics
* \brief Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* \namespace Graphics::Models
	* \brief Namespace for the models in the graphics engine
	*/
	namespace Models {
		/**
		* \class Texture
		* \brief Class contains the data to render
		*/
		class GRAPHICS_API Texture {
		private:
			/**
			* \brief The x coordinate the Texture
			*/
			float _x;

			/**
			* \brief The y coordinate the Texture
			*/
			float _y;

			/**
			* \brief The z coordinate the Texture
			*/
			float _z;

			/**
			* \brief The width of the Texture
			*/
			float _width;

			/**
			* \brief The height of the Texture
			*/
			float _height;

			/**
			* \brief The angle which the Texture
			*/
			float _angle;

			/**
			* \brief The center from the Texture
			*/
			Models::Center _center;

			/**
			* \brief Visibility of Texture
			*/
			bool _visible;

			/**
			* \brief if texture Is_Dynamic
			*/
			bool _is_dynamic;

			/**
			* \brief The path of the Texture
			*/
			std::string _path;

			/**
			* \brief The opacity of the Texture
			* 0 is transparent, 100 is opaque
			*/
			int _opacity;
		protected:
			/**
			* \brief The flip direction of the Texture
			*/
			Enums::FlipEnum _flipstatus;

			/**
			* \brief The TextureFacade that contains the methods to render
			*/
			std::shared_ptr<Facades::TextureFacade> _facade;
		public:
			Texture(float x, float y, float z, float height, float width, float angle, const std::string& path, bool visible, const Models::Center center, bool is_dynamic, int opacity = 100);

			/**
			* \brief Returns the y converted to the perspective from the bottom
			*/
			float get_converted_y(float height) const;

			/**
			* \brief Returns the x coordinate
			*/
			float get_x() const;

			/**
			* \brief Returns the z coordinate
			*/
			float get_z() const;

			/**
			* \brief Returns the z coordinate
			*/
			float get_y() const;

			/**
			* \brief Returns the z coordinate
			*/
			float get_width() const;

			/**
			* \brief Returns the height
			*/
			float get_height() const;

			/**
			* \brief Returns the angle
			*/
			float get_angle() const;

			/**
			* \brief Returns the angle
			*/
			Models::Center get_center() const;

			/**
			* \brief Returns the path to the texture
			*/
			const std::string& get_path() const;

			/**
			* \brief Returns the flip direction
			*/
			Enums::FlipEnum get_flip_status() const;

			/**
			* \brief Returns the visibility
			*/
			bool is_visible() const;

			/**
			* \brief Returns the dynamic
			*/
			bool is_dynamic() const;

			/**
			* \brief Returns the TextureFacade
			*/
			const std::shared_ptr<Facades::TextureFacade> get_texture_facade() const;

			/**
			* \brief Sets the x coordinate
			*/
			void set_x(float x);

			/**
			* \brief Sets the z coordinate
			*/
			void set_z(float z);

			/**
			* \brief Sets the y coordinate
			*/
			void set_y(float y);

			/**
			* \brief Sets the width
			*/
			void set_width(float width);

			/**
			* \brief Sets the height
			*/
			void set_height(float height);

			/**
			* \brief Sets the angle
			*/
			void set_angle(float angle);

			/**
			* \brief Sets the flip status
			*/
			void set_flip_status(Enums::FlipEnum flipstatus);

			/**
			* \brief Sets the visibility
			*/
			void set_visible(bool visibility);

			/**
			* \brief Toggle the visibility
			*/
			void toggle_visible();

			/**
			* \brief Sets the center
			*/
			void set_center(const Models::Center& center);

			/**
			* \brief Returns the opacity of the Texture
			* \return 0 is transparent, 100 is opaque
			*/
			int get_opacity() const;

			/**
			* \brief Sets the facade
			*/
			void set_facade(const std::shared_ptr<Facades::TextureFacade> facade);

			/**
			* \brief Creates the TextureFacade
			*/
			virtual void create_texture_facade() = 0;

			/**
			* \brief Checks if this Texure matches the given Texture
			*/
			virtual bool matches(const std::shared_ptr<Models::Texture> texture) const = 0;
		};
	}
}
