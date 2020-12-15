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
#include <..\Game\Game\src\Views\TimerView.h>
#include <..\Game\Game\src\Views\HighscoreView.h>
#include <..\Game\Game\src\Views\GamePlaySpeedView.h>
#include <..\Game\Game\src\Views\FpsView.h>
#include <..\Game\Game\src\Views\WinLevelView.h>
#include <..\Game\Game\src\Views\GameOverLevelView.h>
#include <..\Game\Game\src\Views\PauseLevelView.h>
#include <..\Game\Game\src\Views\HUDView.h>
#include <..\Game\Game\src\Views\AdvertisementView.h>
#include <..\Game\Game\src\Views\SaveGameView.h>
#include <..\Game\Game\src\Views\CheatsView.h>
#include <..\Game\Game\src\Views\View.h>
#include <..\Game\Game\src\Views\LevelTransitionView.h>
#include <chrono>
#include <thread>
#include "../Models/Abstract/Object.h"
#include "../Enums/ViewEnum.h"
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
			std::map<Enums::ViewEnum, std::unique_ptr<Views::View>> _views;

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

			/**
			* \brief The speed for a View
			*/
			float _speed;
		public:
			WindowController();

			/**
			* \brief Creates the Window
			*/
			void create_window(int height, int width);

			/**
			* \brief Sets the Views active property to true
			*/
			void open_view(Enums::ViewEnum view_name);

			/**
			* \brief Checks if the View is active
			*/
			bool is_active(Enums::ViewEnum view_name);

			/**
			* \brief Close a view based on the enum
			*/
			void close_view(Enums::ViewEnum view_name);

			/**
			* \brief Sets all the Views active property to false
			*/
			void clear_views();

			/**
			* \brief Toggles the visible property of the View
			*/
			void toggle_view_visibility(Enums::ViewEnum view_name);

			/**
			* \brief Calls all draw methods on _views
			*/
			void draw();

			/**
			* \brief Sets the Textures for a View
			*/
			void set_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, Enums::ViewEnum view_name);

			/**
			* \brief dds the Textures for a View
			*/
			void add_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, Enums::ViewEnum view_name);

			/**
			* \brief Sets the speed for a View
			*/
			void set_speed(float speed);

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
			* \brief Returns the camera position
			*/
			std::tuple<int, int> get_camera_pos() const;

			/**
			* \brief Returns the Graphics Controller
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> get_graphics_controller() const;

			/**
			* \brief Add the highscore to the HighscoreView based on a template function
			*/
			template <typename DerivedT>
			void set_highscore_record(std::string record) {
				auto derived = static_cast<DerivedT*>(_views[Enums::ViewEnum::HIGHSCORE].get());
				derived->add_record(record);
			}
		};
	}
}
