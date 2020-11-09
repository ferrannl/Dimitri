#pragma once
#include <memory>
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>
#include <chrono>
#include <thread>
#include "IView.h"
/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the views
	*/
	namespace Views {
		/**
		*	Containing all the code to create and show the credits view
		*/
		class CreditsView : public IView {
		public:
			CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);
			/**
			*	Initializes textures
			*/
			void init_textures();
		};
	}
}
