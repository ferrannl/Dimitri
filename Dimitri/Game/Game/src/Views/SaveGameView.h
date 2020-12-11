#pragma once
#include <..\Game\Game\src\Views\View.h>
#include <src\Helpers\BasePathHelper.h>
#include "../Models/Abstract/Object.h"

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
		* \class SaveGameView
		* \brief Class contains the methods to draw the home screen
		*/
		class SaveGameView : public View {
		public:
			SaveGameView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Initializes Textures
			*/
			void init_textures();

			/**
			* \brief Returns the visible state of the View
			*/
			bool is_visible() const override;
		};
	}
}
