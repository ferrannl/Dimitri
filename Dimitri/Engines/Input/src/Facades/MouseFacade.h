#pragma once
#include <tuple>
#include <SDL.h>
#include <SDL_mouse.h>

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else 
#define INPUT_API __declspec(dllimport)
#endif
#else
#define INPUT_API
#endif

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
		class INPUT_API MouseFacade {
		public:
			/**
			* \brief Returns the X and Y position of the mouse relative to the left corner of the window
			*/
			std::tuple<int, int> get_mouse_position() const;
		};
	}
}