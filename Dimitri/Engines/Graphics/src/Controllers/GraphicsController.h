#pragma once
#include "../Models/Window.h"
#include "../Models/Text.h"
#include <filesystem>
#include <tuple>

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
			int create_window(const std::string& title, const int height, const int width);

			/**
			* Adds the texture to the window
			*/
			void add_texture(const std::shared_ptr<Models::Texture>& texture);

			/**
			* Removes the texture to the window
			*/
			void remove_texture(const std::shared_ptr<Models::Texture>& texture);

			/**
			* Clears all textures from the window
			*/
			void clear_textures();

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

			/**
			* Returns the current fps
			*/
			int get_fps();

			/**
			* Updates camera position
			*/
			void set_camera_pos(const int x, const int y);

			/**
			* Returns camera position
			*/
			std::tuple<int, int> get_camera_pos() const;

			/**
			* Sets level size
			*/
			void set_level_size(const int height, const int width);

			/**
			* Returns level size
			*/
			std::tuple<int, int> get_level_size() const;
		};
	}
}