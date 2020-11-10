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
		class WindowController : public Utility::Interfaces::IObserver<Events::InputEvent> {
		private:
			/**
			*	Graphics Controller to interact with engine
			*/
			std::unique_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;

			/**
			*	Contains all views
			*/
			std::map<std::string, std::unique_ptr<Views::View>> _views;
			/**
			*	Draw thread for updating window in background thread
			*/
			std::thread draw_thread;

			/**
			*	Opens a view by name
			*/
			void open_view(const std::string& view_name);

			/**
			*	Closes all views
			*/
			void clear_views();
		public:
			WindowController();
			/**
			*	Update from Game::Controllers::InputController
			*/
			void update(const Events::InputEvent& object);

			/**
			*	Creates window
			*/
			void create_window(int height, int width);

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
