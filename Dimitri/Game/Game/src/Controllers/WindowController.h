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
#include <..\Game\Game\src\Views/HomeView.h>
#include <..\Game\Game\src\Views\LevelView.h>
#include <..\Game\Game\src\Views\FpsView.h>
#include <..\Game\Game\src\Views\WinLevelView.h>
#include <..\Game\Game\src\Views\GameOverLevelView.h>
#include <..\Game\Game\src\Views\PauseLevelView.h>
#include <..\Game\Game\src\Views\View.h>
#include <chrono>
#include <thread>
#include "../Models/IObject.h"
using namespace std::this_thread;
using namespace std::chrono_literals;

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
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
			*	Sets the textures for the view
			*/
			void set_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, const std::string& view_name);
			
			/**
			*	Adds the textures for the level view
			*/
			void add_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, const std::string& view_name);

			/**
			* Updates camera position
			*/
			void set_camera_pos(int x, int y);

			/**
			* Updates camera position
			*/
			void set_camera_pos_based_on(const std::shared_ptr<Game::Models::IObject> object);

			/**
			* Sets scene size
			*/
			void set_scene_size(int height, int width);

			/**
			*	Getters window height and widht
			*/
			int get_window_height() const;

			int get_window_width() const;
		};
	}
}
