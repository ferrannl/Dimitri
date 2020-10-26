#pragma once
#include "../Facades/WindowFacade.h"
#include "Text.h"
namespace Graphics {
	namespace Models {
		class __declspec(dllexport) Window {
		private:
			int _height;
			int _width;
			const std::string _title;
			std::unique_ptr<Facades::WindowFacade> _facade;
			std::vector<std::shared_ptr<Texture>> _textures; 
			std::shared_ptr<Graphics::Models::Texture> get_texture_by_path(const std::string& path) const;
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