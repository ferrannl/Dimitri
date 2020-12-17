#pragma once
#include <vector>
#include <memory>
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>
#include "../Views/View.h"

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
		* \class CheatsView
		* \brief Class contains the methods to draw the Cheats
		*/
		class CheatsView : public View {
		public:
			CheatsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Returns the visible state of the View
			*/
			bool is_visible() const override;
		};
	}
}