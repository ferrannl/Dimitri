#pragma once
#include <src\Enums\EventEnum.cpp>
#include <tuple>
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