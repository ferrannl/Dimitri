#pragma once
#include <memory>
#include <src\Controllers\GraphicsController.h>
//#include <../Game/Game/src/Controllers/LevelController.h>
#include <src\Helpers\BasePathHelper.h>
#include <..\Game\Game\src\Views\View.h>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Views
	* \brief Namespace for the views in the game
	*/
	namespace Views {
		/**
		* \class FpsView
		* \brief Class contains the methods to draw the fps
		*/
		class TimerView : public View {
		private:

			/**
			* \brief The level controller to update the timer
			*/
			//std::shared_ptr<Game::Controllers::LevelController> _level_controller;
		public:
			TimerView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Updates the textures
			*/
			void update() override;

			/**
			* \brief Removes the textures of the View to the Window in the GraphicsController
			*/
			void close() override;
		};
	}
}
