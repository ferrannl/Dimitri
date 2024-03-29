#pragma once
#include "../Facades/TextureFacade.h"
#include "../Facades/TextFacade.h"
#include "Texture.h"
#include "Color.h"

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
		* \class Text
		* \brief Class contains the data to render text
		*/
		class GRAPHICS_API Text : public Texture {
		private:
			/**
			* \brief The text of the Text
			*/
			const std::string _text;

			/**
			* \brief The color of the Text
			*/
			const Color _color;
		public:
			Text(const std::string& text, const Color& color, float x, float y, float z, float height, float width, float angle, const std::string& path, bool visible, const Models::Center& center, bool is_dynamic, int opacity = 100);

			/**
			* \brief Returns the text
			*/
			const std::string& get_text() const;

			/**
			* \brief Returns the Color
			*/
			const Color& get_color() const;

			/**
			* \brief Creates the TextureFacade
			*/
			void create_texture_facade();

			/**
			* \brief Checks if this Texure matches the given Texture
			*/
			bool matches(const std::shared_ptr<Models::Texture> texture) const;
		};
	}
}