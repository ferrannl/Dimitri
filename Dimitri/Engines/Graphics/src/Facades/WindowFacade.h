#pragma once
#include "../Models/Sprite.h"
#include "../Models/Text.h"
#include "../Adapters/FlipEnumAdapter.h"
#include "src/Time/Fps.h"
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
	* \namespace Graphics::Facades
	* \brief Namespace for the facades in the graphics engine
	*/
	namespace Facades {
		/**
		* \class WindowFacade
		* \brief Class contains the references to the SDL_Window
		*/
		class GRAPHICS_API WindowFacade {
		private:
			/**
			* \brief Contains the fps of the Window
			*/
			std::unique_ptr<Utility::Time::Fps> _fps;

			/**
			* \brief An instance of SDL_Window with a custom destructor
			*/
			std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;

			/**
			* \brief An instance of SDL_Renderer with a custom destructor
			*/
			std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;

			/**
			* \brief The adapter that converts the SDL_FlipEnum to FlipEnum
			*/
			Adapters::FlipEnumAdapter _flip_enum_adapter;

			/**
			* \brief The height of the Window
			*/
			int _window_height;

			/**
			* \brief The width of the Window
			*/
			int _window_width;

			/**
			* \brief The camera position of the Window
			* The standard position of the camera is 0,0
			* \return std::tuple<width, height>
			*/
			std::tuple<int, int> _camera_pos;


			/**
			* \brief The width and height of the Scene
			* \return std::tuple<width, height>
			*/
			std::tuple<int, int> _scene_size;

		public:
			WindowFacade();

			/**
			* \brief Creates the instance of SDL_Renderer
			*/
			int create_renderer();

			/**
			* \brief Returns the SDLGetTicks method
			*/
			Uint32 get_ticks();

			/**
			* \brief Creates the instance of SDL_Window
			*/
			int create_window(const std::string& title, int height, int width);

			/**
			* \brief Creates a TextureFacade or adds an already created TextureFacade if Texture matches
			*/
			void create_texture(const std::shared_ptr<Models::Texture>& texture, const std::shared_ptr<Models::Texture>& matching_texture);

			/**
			* brief Destroys the SDL_Window
			*/
			void destroy();

			/**
			* \brief Updates the window with all the sprites in the given list
			*/
			void update_window(const std::vector<std::shared_ptr<Models::Texture>> textures);

			/**
			* \brief Returns the fps of the Window
			*/
			int get_fps();

			/**
			* brief Updates camera position
			*/
			void set_camera_pos(int x, int y);

			/**
			* brief Returns camera position
			*/
			std::tuple<int, int> get_camera_pos() const;

			/**
			* brief Sets scene size
			*/
			void set_scene_size(int height, int width);

			/**
			* brief Returns scene size
			*/
			std::tuple<int, int> get_scene_size() const;
		};
	}
}