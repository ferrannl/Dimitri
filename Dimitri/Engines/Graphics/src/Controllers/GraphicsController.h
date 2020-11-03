#pragma once
#include "../Models/Window.h"
#include "../Models/Text.h"
#include <filesystem>

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
* Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* Namespace for the controllers
	*/
	namespace Controllers
	{
		/**
		* Containing all the methods needed to display an window and create and show sprites
		*/
		class GRAPHICS_API GraphicsController {
		private:
			/**
			* The window model containing all data for the window
			*/
			std::shared_ptr<Models::Window> _window;
		public:
			GraphicsController();

			/**
			* Creates the window with the given parameters
			*/
			int create_window(const std::string title, const int height, const int width);

			/**
			* Adds the texture to the window
			*/
			void add_texture(const std::shared_ptr<Models::Texture>& texture);
      
			/**
			* Removes the texture to the window
			*/
			void remove_texture(const std::shared_ptr<Models::Texture>& texture);
      
			/**
			* Returns the textures from the window
			*/
			std::vector<std::shared_ptr<Models::Texture>> get_textures() const;

			/**
			* Updates the window
			*/
			void update_window();

			/**
			* Returns the window
			*/
			std::shared_ptr<Models::Window> get_window() const;
		};
	}
}