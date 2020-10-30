#pragma once
#include "../Facades/WindowFacade.h"
#include "Text.h"

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
		class GRAPHICS_API Window {
		private:
			int _height;
			int _width;
			const std::string _title;
			std::unique_ptr<Facades::WindowFacade> _facade;
			std::vector<std::shared_ptr<Texture>> _textures;
			std::shared_ptr<Models::Texture> get_matching_texture(const std::shared_ptr<Models::Texture>& texture) const;

		public:
			Window(const std::string title, const int height, const int width);

			int create();
			void update();
			void destroy();
			void add_texture(const std::shared_ptr<Texture>& texture);
			void remove_texture(const std::shared_ptr<Texture>& texture);
			std::vector<std::shared_ptr<Texture>> get_textures() const;
			int get_height() const;
			int get_width() const;
			const std::string get_title() const;
		};
	}
}