#pragma once
#include <src\Enums\EventEnum.cpp>
#include <tuple>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Events
	* \brief Namespace for the events in the game
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