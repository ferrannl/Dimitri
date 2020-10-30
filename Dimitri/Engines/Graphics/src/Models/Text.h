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
			std::string _text;
			Color _color;
		public:
			Text(const std::string text, const Color color, const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path);
			const std::string get_text() const;
			const Color get_color() const;
			void create_texture_facade();
			bool matches(const std::shared_ptr<Models::Texture>& texture) const;
		};
	}
}