#pragma once
#include "../interfaces/IInputAdapter.h"
namespace Adapters {
	class __declspec(dllexport) KeyBoardAdapter : public Interfaces::IInputAdapter {
	public:
		Enums::EventEnum translate_to_enum(const SDL_Event event) const;
	};
}