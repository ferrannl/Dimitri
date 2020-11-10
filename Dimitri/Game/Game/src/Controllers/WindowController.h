#pragma once
#include <vector>
#include <memory>
#include <map>
#include <string>
#include <thread>
#include <src\Controllers\GraphicsController.h>
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include "../Views/CreditsView.h"
#include "../Views/LevelView.h"
#include "../Views/FpsView.h"
#include "../Views/View.h"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the controllers
	*/
	namespace Controllers {
		/**
		*	Contains all code to interact with window engine and show images on screen
		*/
		class WindowController {
		private:
			/**
			*	Graphics Controller to interact with engine
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;

			/**
			*	Contains all views
			*/
			std::map<std::string, std::unique_ptr<Views::View>> _views;

			/**
			*	Draw thread for updating window in background thread
			*/
			std::thread draw_thread;
		public:
			WindowController();

			/**
			*	Creates window
			*/
			void create_window(int height, int width);

			/**
			*	Sets the views active property to true
			*/
			void open_view(const std::string& view_name);

			/**
			*	Sets all the views active property to false
			*/
			void clear_views();

			/**
			*	Toggles the visible property of view
			*/
			void toggle_view_visibility(const std::string& view_name);

			/**
			* returns _width
			*/
			void draw();

			/**
			*	Sets the textures for the level view
			*/
			void set_level_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures);
		};
	}
}
