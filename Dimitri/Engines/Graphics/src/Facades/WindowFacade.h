#pragma once
#include "../Models/Sprite.h"
#include "../Models/Text.h"
#include "../Adapters/FlipEnumAdapter.h"
#include "src/Time/Fps.h"

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
			Utility::Time::Fps fps = {};
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
			*	x and y pos of camera standard 0,0
			*/
			int _camera_x = 0;
			int _camera_y = 0;
			/**
			*	Height and width of level standard equal to window height and width but can be increased for large levels
			*/
			int _level_height;
			int _level_width;

		public:
			WindowFacade();

			/**
			* Creates the instance of SDL_Renderer
			*/
			int create_renderer();

			/**
			* Creates the instance of SDL_Window
			*/
			int create_window(const std::string title, const int height, const int width);

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

			void switch_fps();

			/**
			* Updates camera position
			*/
			void set_camera_pos(const int x, const int y);

			/**
			* Sets level size
			*/
			void set_level_size(const int height, const int width);
		};
	}
}