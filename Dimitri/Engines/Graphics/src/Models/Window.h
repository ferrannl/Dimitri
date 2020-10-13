#pragma once
#include "../Facades/WindowFacade.h"

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

namespace Models {
	class GRAPHICS_API Window {
	private:
		int _height; ///< Height of the window
		int _width; ///< Height of the window
		const std::string _title; ///< Title of the window
		std::unique_ptr<Facades::WindowFacade> _facade; ///< Facade containing references to SDL
		std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> _sprites; ///< List containing all the sprites of the window

	public:
		// Constructor
		Window(const std::string title, const int height, const int width);
			
		int create(); //< Creates a window
		void update(); //< Updates a window
		void destroy();  //< Destroys a window
		void set_sprites(const std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> sprites);  //< Set the sprites of a window
		std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> get_sprites() const;  //< Get the sprites of a window
		int get_height() const;  //< Get the height of the window
		int get_width() const;  //< Get the width of a window
		const std::string get_title() const;  //< Get the title of a window
	};
}
