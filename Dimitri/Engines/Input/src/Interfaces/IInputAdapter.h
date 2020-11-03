#pragma once
#include "../enums/EventEnum.cpp"
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

namespace Input {
	namespace Interfaces {
		class INPUT_API IInputAdapter {
		public:
			virtual Enums::EventEnum translate_to_enum(const SDL_Event event) const = 0;
		};
	}
}
