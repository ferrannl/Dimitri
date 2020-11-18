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
* Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* Namespace for the facades
	*/
	namespace Facades {
		/**
		* Contains all the references needed for the SDL_Window
		*/
		class GRAPHICS_API WindowFacade {
		private:
			/**
			* An instance of FPS.
			*/
			std::unique_ptr<Utility::Time::Fps> _fps;
			/**
		   * An instance of SDL_Window. The SDL_Destroywindow has to be passed by reference becuase SDL_Window has a custom destructor.
		   */
			std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;

			/**
			* An instance of SDL_Renderer. The SDL_DestroyRenderer has to be passed by reference becuase SDL_Renderer has a custom destructor.
			*/
			std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;

			/**
			* The adapter that converts the SDL_Flipenum to FlipEnum
			*/
			Adapters::FlipEnumAdapter _flip_enum_adapter;

			/**
			*	Everything beneath this is for sidescrolling managment
			*/

			/**
			*	Height and width of the window
			*/
			int _window_height;
			int _window_width;

			/**
			*	x and y pos of camera standard 0,0; 0 = x, 1 = y
			*/
			std::tuple<int, int> _camera_pos;

			/**
			*	Height and width of scene standard equal to window height and width but can be increased for large levels; 0 = width, 1 = height
			*/
			std::tuple<int, int> _scene_size;

		public:
			WindowFacade();

			/**
			* Creates the instance of SDL_Renderer
			*/
			int create_renderer();

			/**
			* Creates the instance of SDL_Window
			*/
			int create_window(const std::string& title, int height, int width);

			/**
			* Creates a TextureFacade or adds a already created TextureFacade if Texture matches
			*/
			void create_texture(const std::shared_ptr<Models::Texture>& texture, const std::shared_ptr<Models::Texture>& matching_texture);

			/**
			* Destroys the SDL_Window
			*/
			void destroy();

			/**
			* Updates the window with all the sprites in the given list
			*/
			void update_window(const std::vector<std::shared_ptr<Models::Texture>> textures);

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