#pragma once
#include <src\Enums\EventEnum.h>
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
		* \class InputEvent
		* \brief Class contains the data of the user input
		*/
		class InputEvent {
		public:
			InputEvent(Input::Enums::EventEnum event_enum, std::tuple<int, int> mouse_pos);

			/**
			* \brief An instance of EventEnums that represent the pressed key
			*/
			Input::Enums::EventEnum event_enum;

			/**
			* \brief Current mouse position
			*/
			std::tuple<int, int> mouse_pos;
		};
	}
}