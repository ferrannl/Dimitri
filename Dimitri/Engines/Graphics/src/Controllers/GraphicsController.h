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
	namespace Controllers {
		/**
		* \class GraphicsController
		* \brief Class contains the methods to handle a Window and Textures
		*/
		class GRAPHICS_API GraphicsController {
		private:
			/**
			* \brief The Window containing the Textures
			*/
			std::shared_ptr<Models::Window> _window;
		public:
			GraphicsController();

			/**
			* \brief Creates the Window with the given parameters
			*/
			int create_window(const std::string& title, int height, int width);

			/**
			* \brief Adds a Texture to the window
			*/
			void add_texture(const std::shared_ptr<Models::Texture>& texture);

			/**
			* \brief Removes a Texture from the window
			*/
			void remove_texture(const std::shared_ptr<Models::Texture>& texture);

			/**
			* \brief Clears all Textures from the window
			*/
			void clear_textures();

			/**
			* \brief Returns the Textures from the window
			*/
			std::vector<std::shared_ptr<Models::Texture>> get_textures() const;

			/**
			* \brief Updates the Window
			*/
			void update_window();

			/**
			* \brief Returns the Window
			*/
			std::shared_ptr<Models::Window> get_window() const;

			/**
			* \brief Returns the current fps
			*/
			int get_fps();

			/**
			* \brief Returns the current ticks
			*/
			Uint32 get_ticks();

			/**
			* Updates camera position
			*/
			void set_camera_pos(int x, int y);

			/**
			* \brief Returns camera position
			*/
			std::tuple<int, int> get_camera_pos() const;

			/**
			* \brief Sets scene size
			*/
			void set_scene_size(int height, int width);

			/**
			* \brief Returns scene size
			*/
			std::tuple<int, int> get_scene_size() const;
		};
	}
}