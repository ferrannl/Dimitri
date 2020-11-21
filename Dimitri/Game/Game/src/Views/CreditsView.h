#pragma once
#include <..\Game\Game\src\Views\View.h>
#include <src\Helpers\BasePathHelper.h>

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
