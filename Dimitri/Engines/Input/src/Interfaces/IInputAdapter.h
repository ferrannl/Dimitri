#pragma once
#include "../enums/EventEnum.h"
#include <SDL.h>

/**
* \namespace Input
* \brief Namespace for the input engine
*/
namespace Input {
	/**
	* \namespace Input::Interfaces
	* \brief Namespace for the interfaces in the input engine
	*/
	namespace Interfaces {
		/**
		* \class IInputAdapter
		* \brief Class contains the methods to translate the SDL_events to EventEnum
		*/
		class IInputAdapter {
		public:
			/**
			* \brief Translates the SDL_events to EventEnum
			*/
			virtual Enums::EventEnum translate_to_enum(const SDL_Event& event) const = 0;
		};
	}
}
