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
		* \class GameOverLevelView
		* \brief Class contains the methods to draw the game over menu
		*/
		class GameOverLevelView : public View {
		public:
			GameOverLevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Initializes textures
			*/
			void init_textures();

			/**
			* \brief Returns if view is visible
			*/
			bool is_visible() const override;

			/**
			* \brief Add the textures to the _graphics_controller
			*/
			void draw() override;
		};
	}
}