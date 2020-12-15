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
		* \class GamePlaySpeedView
		* \brief Class contains the methods to draw the gameplay speed
		*/
		class GamePlaySpeedView : public View {
		private:
			std::string path_text;
		public:
			GamePlaySpeedView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Updates the textures
			*/
			void update() override;

			/**
			* \brief Removes the textures of the View to the Window in the GraphicsController
			*/
			void close() override;

			/**
			* \brief Returns the visible state of the View
			*/
			bool is_visible() const override;

		};
	}
}
