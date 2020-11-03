#pragma once
#include <tuple>
#include <src\Enums\EventEnum.cpp>

namespace Game {
	namespace Models {
		class InputEvent {
		public:
			Input::Enums::EventEnum event_enum;
			std::tuple<int, int> mouse_pos;
			InputEvent(Input::Enums::EventEnum event_enum, std::tuple<int, int> mouse_pos);
		};
	}
}
