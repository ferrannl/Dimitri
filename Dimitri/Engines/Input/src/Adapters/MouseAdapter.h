#pragma once
#include <tuple>
#include "../interfaces/IInputAdapter.h"
namespace Input {
	namespace Adapters {
		class __declspec(dllexport) MouseAdapter : public Interfaces::IInputAdapter {
		public:
			Enums::EventEnum translate_to_enum(const SDL_Event event) const;
		};
	}
}

