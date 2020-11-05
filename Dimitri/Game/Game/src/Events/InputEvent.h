#pragma once
#include <src\Enums\EventEnum.cpp>
#include <tuple>
/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the events
	*/
	namespace Events {
		/**
		*	Contains code to keep track of user input
		*/
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