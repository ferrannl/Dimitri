#pragma once
#include <tuple>
#include "../enums/EventEnum.cpp"
#include "../interfaces/IInputAdapter.h"
namespace Adapters {
	class __declspec(dllexport) MouseAdapter : public Interfaces::IInputAdapter {
	public:
		Enums::EventEnum translate_to_enum(const SDL_Event event) const;
	};
}

