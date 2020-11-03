#pragma once
#include <src\Enums\EventEnum.cpp>
#include <tuple>
namespace Game {
	namespace Events {
		class InputEvent {
		public:
			/**
			*	Event Enum to know which key was pressed
			*/
			Input::Enums::EventEnum event_enum;
			/**
			*	Current mouse position
			*/
			std::tuple<int, int> mouse_pos;
			InputEvent(Input::Enums::EventEnum event_enum, std::tuple<int, int> mouse_pos);
		};
	}
}