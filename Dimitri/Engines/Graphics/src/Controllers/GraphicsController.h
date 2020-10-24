#pragma once

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

#include "../Models/Window.h"
#include <filesystem>

/**
* Namespace for all the Controllers in the project
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
		 * Adds the sprites to the window
		 */
		 void add_sprites(std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites);

		 /**
		 * Returns the sprites from the window
		 */
		 std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> get_sprites() const;
		 
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