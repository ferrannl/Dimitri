#pragma once
#include <iostream>
#include <src\Controllers\InputController.h>
#include "../Events/InputEvent.h"
#include <vector>
#include <tuple>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
	*/
	namespace Controllers {
		/**
		*	Contains code to get update events from input engine and send these updates to the observers
		*/
		class InputController : public Utility::Interfaces::IObserver<Input::Enums::EventEnum>, public std::enable_shared_from_this<InputController>, public Utility::Interfaces::IObservable<Game::Events::InputEvent> {
		private:
			/**
			*	Input Controller to interact with input engine
			*/
			std::unique_ptr<Input::Controllers::InputController> _input_controller;
			/**
			*	List of observers
			*/
			std::vector<std::shared_ptr<Utility::Interfaces::IObserver<Game::Events::InputEvent>>> _observers;
		public:
			InputController();
			/**
			*	Polls events in input engine
			*/
			void poll_events();
			/**
			*	Receive event from engine
			*/
			void update(const Input::Enums::EventEnum& object);
			/**
			*	Notifies observables
			*/
			void notify(const Game::Events::InputEvent& object);
			/**
			*	Add observer to list of observables
			*/
			void subscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Game::Events::InputEvent>>& observer);

			/**
			* Removes observer from list of observables
			*/
			void unsubscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Game::Events::InputEvent>>& observer);
		};
	}
}
