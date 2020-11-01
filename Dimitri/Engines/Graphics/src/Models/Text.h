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

namespace Graphics {
	namespace Models {
		class GRAPHICS_API Text : public Texture {
		private:
			/**
			* The text of the Text
			*/

			std::string _text;
			/**
			* The color of the Text
			*/
			Color _color;
		public:
			Text(const std::string text, const Color color, const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path);

			/**
			* returns the text
			*/
			const std::string get_text() const;

			/**
			* returns the color
			*/
			const Color get_color() const;

			/**
			* creates the texture facade
			*/
			void create_texture_facade();

			/**
			* Checks if this texure matches the given texture
			*/
			bool matches(const std::shared_ptr<Models::Texture>& texture) const;
		};
	}
}