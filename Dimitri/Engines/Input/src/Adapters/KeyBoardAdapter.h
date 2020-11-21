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
* \namespace Input
* \brief Namespace for the input engine
*/
namespace Input {
	/**
	* \namespace Input::Adapters
	* \brief Namespace for the adapters in the input engine
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