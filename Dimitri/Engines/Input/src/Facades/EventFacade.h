#pragma once
#include "../Adapters/KeyBoardAdapter.h"
#include "../Adapters/MouseAdapter.h"
#include <memory>
#include <SDL.h>

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
		* \class EventFacade
		* \brief Class contains the methods to get fired events using SDL
		*/
		class INPUT_API EventFacade {
		private:
			/**
			* \brief An instance of SDL_Event
			*/
			SDL_Event _event;

			/**
			* \brief Adapter used to translate the SDL events to the EvenEnum
			*/
			std::shared_ptr<Interfaces::IInputAdapter> _input_adapter;
		public:
			EventFacade();

			/**
			* \brief Returns the events that are fired
			*/
			Enums::EventEnum poll_event();
		};
	}
}
