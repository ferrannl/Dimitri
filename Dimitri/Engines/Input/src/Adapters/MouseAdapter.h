#pragma once
#include <tuple>
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

namespace Adapters {
	class INPUT_API MouseAdapter : public Interfaces::IInputAdapter {
	public:
		Enums::EventEnum translate_to_enum(const SDL_Event event) const;
	};
}

