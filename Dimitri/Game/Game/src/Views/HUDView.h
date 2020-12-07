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
		* \class HudView
		* \brief Class contains the methods to draw the hud
		*/
		class HUDView : public View {
		public:
			HUDView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Initializes Textures
			*/
			void init_textures();

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
