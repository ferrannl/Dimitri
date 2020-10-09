#include "InputController.h"

Controllers::InputController::InputController() : Interfaces::IObservable()
{
	_event_facade = std::make_unique<Facades::EventFacade>();
	_mouse_facade = std::make_unique<Facades::MouseFacade>();
	_observers = {};
}

std::tuple<int, int> Controllers::InputController::get_mouse_position()
{
	return _mouse_facade->get_mouse_position();
}

void Controllers::InputController::notify(Enums::EventEnum event)
{
	for (std::shared_ptr<Interfaces::IObserver> observer : _observers) {
		observer->update(event);
	}
}

void Controllers::InputController::subscribe(std::shared_ptr<Interfaces::IObserver> observer)
{
	_observers.push_back(observer);
}


void Controllers::InputController::poll_events()
{
	while (true) {
		Enums::EventEnum event = _event_facade->poll_event();
		if (event != Enums::EventEnum::NOT_SUPPORTED) {
			notify(event);
		}
	}
}
