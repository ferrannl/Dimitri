#pragma once
#include "../interfaces/IInputAdapter.h"

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
	* Namespace for the adapters
	*/
	namespace Adapters {
		/**
		* Containing method to translate SDL events to EventEnum
		*/
		class INPUT_API KeyBoardAdapter : public Interfaces::IInputAdapter {
		public:
			/**
			* Method to translate SDL events to EventEnum that are being used for the keyboard
			*/
			Enums::EventEnum translate_to_enum(const SDL_Event event) const;
		};
	}
}