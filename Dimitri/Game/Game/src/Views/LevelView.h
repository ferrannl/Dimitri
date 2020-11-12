#pragma once
#include <vector>
#include <memory>
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>
#include <..\Game\Game\src\Views\View.h>

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the views
	*/
	namespace Views {
		/**
		*	Containing all the code to draw the level using the graphics controller
		*/
		class LevelView : public View {
		public:
			LevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);
			/**
			* Add the textures to the _graphics_controller
			*/
			void draw();

			/**
			*	Returns if view is visible
			*/
			bool is_visible() const override;
		};
	}
}