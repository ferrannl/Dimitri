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
		* \class HelpView
		* \brief Class contains the methods to draw the help instuctions
		*/
		class HelpView : public View {
		public:
			HelpView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Initializes textures
			*/
			void init_textures();

			/**
			* \brief Returns if view is visible
			*/
			bool is_visible() const override;
		};
	}
}
