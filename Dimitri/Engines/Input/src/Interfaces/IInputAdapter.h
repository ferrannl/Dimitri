#pragma once
#include "../enums/EventEnum.h"
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
	* \namespace Input::Interfaces
	* \brief Namespace for the interfaces in the input engine
	*/
	namespace Interfaces {
		/**
		* \class IInputAdapter
		* \brief Class contains the methods to translate the SDL_events to EventEnum
		*/
		class INPUT_API IInputAdapter {
		public:
			/**
			* \brief Translates the SDL_events to EventEnum
			*/
			virtual Enums::EventEnum translate_to_enum(const SDL_Event event)const = 0;
		};
	}
}
