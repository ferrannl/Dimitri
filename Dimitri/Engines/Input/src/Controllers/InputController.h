#pragma once
#include "../Facades/EventFacade.h"
#include "../Facades/MouseFacade.h"
#include <SDL.h>
#include "../../../../Utility/src/Interfaces/IObservable.h"
#include "../../../../Utility/src/Interfaces/IObserver.h"
#include <chrono>
#include <thread>
#include <vector>
using namespace std::this_thread;
using namespace std::chrono_literals;

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else 
#define INPUT_API __declspec(dllimport)
#endif
#else
#define INPUT_API
#endif

/**
* \namespace Input
* \brief Namespace for the input engine
*/
namespace Input {
	/**
	* \namespace Input::Controllers
	* \brief Namespace for the controllers in the input engine
	*/
	namespace Controllers {
		/**
		* \class InputController
		* \brief Class contains the methods the method to get the fired events
		*/
		class INPUT_API InputController : public Utility::Interfaces::IObservable<Enums::EventEnum> {
		private:
			/**
			* \brief The Observers that observe the EventEnum
			*/
			std::vector<std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>>> _observers;

			/**
			* \brief An instance of the MouseFacade to get the mouse position
			*/
			std::unique_ptr<Facades::MouseFacade> _mouse_facade;

			/**
			* \brief An instance of the EventFacade to get the keyboard events
			*/
			std::unique_ptr<Facades::EventFacade> _event_facade;

		public:
			InputController();

			/**
			* \brief Returns the X and Y position of the mouse relative to the left corner of the window
			*/
			std::tuple<int, int> get_mouse_position();

			/**
			* \brief Notifies the Observers
			*/
			void notify(const Enums::EventEnum& object);

			/**
			* \brief Subscribes on this observable
			*/
			void subscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>>& observer);

			/**
			* \brief Unsubscribes on this observable
			*/
			void unsubscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>>& observer);
			
			/**
			* \brief Notifies observers if event is fired
			*/
			void poll_events();
		};
	}
}