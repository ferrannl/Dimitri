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
* \namespace Graphics
* \brief Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* \namespace Graphics::Controllers
	* \brief Namespace for the controllers in the graphics engine
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
			int create_window(const std::string& title, int height, int width);

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
			void set_camera_pos(int x, int y);

			/**
			* Returns camera position
			*/
			std::tuple<int, int> get_camera_pos() const;

			/**
			* Sets scene size
			*/
			void set_scene_size(int height, int width);

			/**
			* Returns scene size
			*/
			std::tuple<int, int> get_scene_size() const;
		};
	}
}