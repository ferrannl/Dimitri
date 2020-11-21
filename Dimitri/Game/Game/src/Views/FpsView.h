#pragma once
#include <memory>
#include <src\Controllers\GraphicsController.h>
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
		*	Containing all the code to draw the fps using the graphics controller
		*/
		class FpsView : public View {
		public:
			FpsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);
			/**
			* Add the textures to the _graphics_controller
			*/
			void draw() override;
		};
	}
}
