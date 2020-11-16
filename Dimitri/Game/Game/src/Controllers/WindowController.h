#pragma once
#include <vector>
#include <memory>
#include <map>
#include <string>
#include <thread>
#include <src\Controllers\GraphicsController.h>
#include <src\Interfaces\IObserver.h>
#include <..\Game\Game\src\Events\InputEvent.h>
#include <..\Game\Game\src\Views/CreditsView.h>
#include <..\Game\Game\src\Views/HelpView.h>
#include <..\Game\Game\src\Views\LevelView.h>
#include <..\Game\Game\src\Views\FpsView.h>
#include <..\Game\Game\src\Views\WinLevelView.h>
#include <..\Game\Game\src\Views\GameOverLevelView.h>
#include <..\Game\Game\src\Views\PauseLevelView.h>
#include <..\Game\Game\src\Views\View.h>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

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
			bool _open_window;

			/**
			*	Height and width of window
			*/
			int _height;
			int _width;

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
			*	Checks if the view is active
			*/
			bool is_active(const std::string& view_name);

			/**
			*	Sets all the views active property to false
			*/
			void clear_views();

			/**
			*	Toggles the visible property of view
			*/
			void toggle_view_visibility(const std::string& view_name);

			/**
			*	Calls all draw methods on _views
			*/
			void draw();

			/**
			*	Sets the textures for the level view
			*/
			void set_level_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures);

			/**
			* Updates camera position
			*/
			void set_camera_pos(const int x, const int y);

			/**
			* Sets level size
			*/
			void set_level_size(const int height, const int width);

			/**
			*	Getters window height and widht
			*/
			int get_window_height() const;

			int get_window_width() const;
		};
	}
}
