#pragma once
#include <vector>
#include <memory>
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>
#include <chrono>
#include <thread>
#include "IView.h"

using namespace std::this_thread;
using namespace std::chrono_literals;
/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the views
	*/
	namespace Views {
		/**
		*	Containing all the code to draw the level using the graphics controller
		*/
		class LevelView : public IView {
		public:
			LevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);
			/**
			*	Initializes textures
			*/
			void init_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures);
		};
	}
}