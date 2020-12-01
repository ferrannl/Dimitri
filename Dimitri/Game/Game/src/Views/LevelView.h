#pragma once
#include <vector>
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
		* \class LevelView
		* \brief Class contains the methods to draw the level
		*/
		class LevelView : public View {
		public:
			LevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Returns the visible state of the View
			*/
			bool is_visible() const override;
		};
	}
}