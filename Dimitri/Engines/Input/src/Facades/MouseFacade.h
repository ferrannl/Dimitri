#pragma once
#include <tuple>

/**
* \namespace Input
* \brief Namespace for the input engine
*/
namespace Input {
	/**
	* \namespace Input::Facades
	* \brief Namespace for the facades in the input engine
	*/
	namespace Facades {
		/**
		* \class MouseFacade
		* \brief Class contains the methods to get the mouse events using SDL
		*/
		class MouseFacade {
		public:
			/**
			* \brief Returns the X and Y position of the mouse relative to the left corner of the window
			*/
			const std::tuple<int, int> get_mouse_position() const;
		};
	}
}