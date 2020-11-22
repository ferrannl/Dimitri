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
		* \class InputController
		* \brief Class contains the methods to interact with the input engine and fire events to the game
		*/
		class InputController : public Utility::Interfaces::IObserver<Input::Enums::EventEnum>, public std::enable_shared_from_this<InputController>, public Utility::Interfaces::IObservable<Game::Events::InputEvent> {
		private:
			/**
			* \brief An instance of the InputController to interact with input engine
			*/
			std::unique_ptr<Input::Controllers::InputController> _input_controller;

			/**
			* \brief List of observers
			*/
			std::vector<std::shared_ptr<Utility::Interfaces::IObserver<Game::Events::InputEvent>>> _observers;
		public:
			InputController();
			/**
			* \brief Polls events from the input engine
			*/
			void poll_events();

			/**
			* \brief Receives event from the input engine
			*/
			void update(const Input::Enums::EventEnum& object);

			/**
			* \brief Notifies the Observables
			*/
			void notify(const Game::Events::InputEvent& object);

			/**
			* \brief Add observer to list of observables
			*/
			void subscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Game::Events::InputEvent>>& observer);

			/**
			* \brief Removes observer from list of observables
			*/
			void unsubscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Game::Events::InputEvent>>& observer);
		};
	}
}
