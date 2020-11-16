#pragma once
#include <..\Game\Game\src\Views\View.h>
#include <src\Helpers\BasePathHelper.h>
#include "../Models/IObject.h"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the views
	*/
	namespace Views {
		/**
		*	Containing all the code to draw the HomeView using the graphics controller
		*/
		class HomeView : public View {
		public:
			HomeView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

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

			/**
			*	Home background
			*/
			std::shared_ptr<Graphics::Models::Texture> _background;

			/**
			*	New Game Button
			*/
			std::shared_ptr<Game::Models::IObject> _buttonPlayGame;

			/**
			*	Exit Game Button
			*/
			std::shared_ptr<Game::Models::IObject> _buttonExitGame;

		};
	}
}
