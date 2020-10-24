#pragma once
#include <SDL.h>
#include "../enums/EventEnum.cpp"
namespace Input {
	namespace Interfaces {
		class __declspec(dllexport) IInputAdapter {
		public:
			virtual Enums::EventEnum translate_to_enum(const SDL_Event event)const = 0;
		};
	}
}