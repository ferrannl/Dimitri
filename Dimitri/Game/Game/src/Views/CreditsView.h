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
		class CreditsView : public View {
		public:
			CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			*	Initializes textures
			*/
			void init_textures();

			/**
			*	Returns if view is visible
			*/
			bool is_visible() const override;
		};
	}
}
