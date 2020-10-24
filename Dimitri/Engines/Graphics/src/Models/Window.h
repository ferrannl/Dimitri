#pragma once
#include "../Facades/WindowFacade.h"

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else GRAPHICS_API __declspec(import)
#endif
#else
#define GRAPHICS_API
#endif

namespace Models {
	class GRAPHICS_API Window {
	private:
		int _height;
		int _width;
		const std::string _title;
		std::unique_ptr<Facades::WindowFacade> _facade;
		std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> _sprites;

	public:
		Window(const std::string title, const int height, const int width);
			
		int create();
		void update();
		void destroy();
		void set_sprites(const std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> sprites);
		std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> get_sprites() const;
		int get_height() const;
		int get_width() const;
		const std::string get_title() const;
	};
}
