#pragma once
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
		* \class AdvertisementView
		* \brief Class contains the methods to draw the advertisments
		*/
		class AdvertisementView : public View {
		public:
			AdvertisementView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Adds the textures of the View to the Window in the GraphicsController
			*/
			void open() override;

			/**
			* \brief Returns the visible state of the View
			*/
			bool is_visible() const override;
		};
	}
}
