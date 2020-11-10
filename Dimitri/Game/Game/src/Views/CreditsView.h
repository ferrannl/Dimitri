#pragma once
#include "View.h"
#include <src\Helpers\BasePathHelper.h>

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the views
	*/
	namespace Views {
		/**
		*	Containing all the code to draw the credits using the graphics controller
		*/
		class CreditsView : public View {
		public:
			CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);
			/**
			*	Initializes textures
			*/
			void init_textures();
			/**
			* Add the textures to the _graphics_controller
			*/
			void draw();
		};
	}
}
