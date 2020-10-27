#pragma once
#include "../Facades/TextureFacade.h"
#include "../Facades/TextFacade.h"
#include "Texture.h"

namespace Graphics {
	namespace Models {
		class __declspec(dllexport) Text : public Texture {
		private:
			std::string _text;
			uint8_t _color_red;
			uint8_t _color_green;
			uint8_t _color_blue;
		public:
			Text(const std::string text, const uint8_t color_red, uint8_t color_green, const uint8_t color_blue, const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path);
			const std::string get_text() const;
			const uint8_t get_color_red() const;
			const uint8_t get_color_green() const;
			const uint8_t get_color_blue() const;
			const int get_size() const;
			void create_texture_facade();
			bool matches(const std::shared_ptr<Models::Texture>& texture) const;
		};
	}
}