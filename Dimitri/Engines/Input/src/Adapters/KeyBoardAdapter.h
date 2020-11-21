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
		* \class KeyBoardAdapter
		* \brief Class contains the methods to translate SDL events to EventEnum
		*/
		class INPUT_API KeyBoardAdapter : public Interfaces::IInputAdapter {
		public:
			/**
			* \brief Translates SDL events to EventEnum that are fires by a keyboard
			*/
			Enums::EventEnum translate_to_enum(const SDL_Event event) const;
		};
	}
}