#pragma once
#include "../Views/View.h"
#include "../Views/View.h"
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
		* \class CreditsView
		* \brief Class contains the methods to draw the credits
		*/
		class CreditsView : public View {
		public:
			CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

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
