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
#include "../Models/Abstract/Object.h"
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
		* \class WindowController
		* \brief Class contains the methods to open the Views
		*/
		class WindowController {
		private:
			/**
			* \brief An instance of the GraphicsController to interact with graphics engine
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;

			/**
			* \brief A List of all the Views
			*/
			std::map<std::string, std::unique_ptr<Views::View>> _views;

			/**
			* \brief A thread for rendering Textures on the Window
			*/
			std::thread draw_thread;

			/**
			* \brief The height of the Window
			*/
			int _height;

			/**
			* \brief The width of the Window
			*/
			int _width;

		public:
			WindowController();

			/**
			* \brief Creates the Window
			*/
			void create_window(int height, int width);

			/**
			* \brief Sets the Views active property to true
			*/
			void open_view(const std::string& view_name);

			/**
			* \brief Checks if the View is active
			*/
			bool is_active(const std::string& view_name);

			/**
			* \brief Sets all the Views active property to false
			*/
			void clear_views();

			/**
			* \brief Toggles the visible property of the View
			*/
			void toggle_view_visibility(const std::string& view_name);

			/**
			* \brief Calls all draw methods on _views
			*/
			void draw();

			/**
			* \brief Sets the Textures for a View
			*/
			void set_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, const std::string& view_name);

			/**
			*	 \brief dds the Textures for a View
			*/
			void add_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, const std::string& view_name);

			/**
			* \brief Updates camera position
			*/
			void set_camera_pos(int x, int y);

			/**
			* \brief Updates camera position based on a Object
			*/
			void set_camera_pos_based_on(const std::shared_ptr<Game::Models::Object> object);

			/**
			* \brief Sets scene size
			*/
			void set_scene_size(int height, int width);

			/**
			* \brief Returns the height of the Window
			*/
			int get_window_height() const;

			/**
			* \brief Returns the width of the Window
			*/
			int get_window_width() const;

			/**
			* Get graphics controller
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> get_graphics_controller();
		};
	}
}
