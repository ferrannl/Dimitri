#pragma once
#include "../Models/Sprite.h"
#include "../Adapters/FlipEnumAdapter.h"

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
* Namespace for all the facades in the project
*/
namespace Facades {
	/**
	* Contains all the references needed for the SDL_Window
	*/
	class GRAPHICS_API WindowFacade {
	private:
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
		* Checks if the texturefacade already exists for a other sprite. If this is the case a pointer to this Texturefacade will be returned. This way memory will be saved.
		*/
		std::shared_ptr<Facades::TextureFacade> get_if_exists(const std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites, const std::string path);
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
		* Creates all the sprites in the given list
		*/
		void create_sprites(const std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites);

		/**
		* Destroys the SDL_Window
		*/
		void destroy();

		/**
		* Updates the window with all the sprites in the given list
		*/
		void update_window(const std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites);
	};
}