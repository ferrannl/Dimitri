#pragma once
#include <..\Game\Game\src\Views\View.h>
#include <src\Helpers\BasePathHelper.h>

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the views
	*/
	namespace Views {
		/**
		*	Containing all the code to draw the credits using the graphics controller
		*/
		class HelpView : public View {
		public:
			HelpView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			*	Initializes textures
			*/
			void init_textures();

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
