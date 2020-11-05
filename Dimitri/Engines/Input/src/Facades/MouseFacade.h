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
* Namespace for the input engine
*/
namespace Input {
	/**
	* Namespace for the facades
	*/
	namespace Facades {
		/**
		* Containing all methods and references needed for the mouse events from SDL
		*/
		class INPUT_API MouseFacade {
		public:
			/**
			* Returns the X and Y where the mouse has clicked
			*/
			std::tuple<int, int> get_mouse_position() const;
		};
	}
}