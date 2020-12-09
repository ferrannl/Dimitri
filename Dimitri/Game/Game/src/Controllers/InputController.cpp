#include "InputController.h"

using namespace Game;
Controllers::InputController::InputController(const std::shared_ptr<Controllers::WindowController> window_controller) : _window_controller{ window_controller } {
	_input_controller = std::make_unique<Input::Controllers::InputController>();
}

void Game::Controllers::InputController::poll_events() {
	_input_controller->subscribe(this->shared_from_this());
	_input_controller->poll_events();
}

void Game::Controllers::InputController::update(const Input::Enums::EventEnum& object)
{
	std::tuple<int, int> pos = _input_controller->get_mouse_position();
	std::get<1>(pos) = _window_controller->get_window_height() - std::get<1>(pos) ;
	notify(Game::Events::InputEvent(object, pos));
}

void Game::Controllers::InputController::notify(const Game::Events::InputEvent& object) {
	for (auto observer : _observers) {
		observer->update(object);
	}
}

void Game::Controllers::InputController::subscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Game::Events::InputEvent>>& observer) {
	_observers.push_back(observer);
}

void Game::Controllers::InputController::unsubscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Game::Events::InputEvent>>& observer)
{
	if (std::find(_observers.begin(), _observers.end(), observer) != _observers.end()) {
		_observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
	}
}
