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
			CreditsView(float widht, float height);
			/**
			*	Initializes textures
			*/
			void init_textures();
		};
	}
}
