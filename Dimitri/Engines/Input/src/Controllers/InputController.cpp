#include "InputController.h"
using namespace Input;

Controllers::InputController::InputController() :
	_event_facade{ std::make_unique<Facades::EventFacade>() }, _mouse_facade{ std::make_unique<Facades::MouseFacade>() } {}

std::tuple<int, int> Controllers::InputController::get_mouse_position()
{
	return _mouse_facade->get_mouse_position();
}

void Controllers::InputController::notify(const Enums::EventEnum& object)
{
	for (auto& observer : _observers) {
		observer->update(object);
	}
}

void Controllers::InputController::subscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>> observer)
{
	_observers.push_back(observer);
}

void Input::Controllers::InputController::unsubscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>> observer)
{
	_observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
}

void Controllers::InputController::poll_events()
{
	while (true) {
		sleep_for(5ms);
		Enums::EventEnum event = _event_facade->poll_event();
		if (event != Enums::EventEnum::NOT_SUPPORTED) {
			notify(event);
		}
	}
}
