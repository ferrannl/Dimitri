#include "InputController.h"

using namespace Game;
Controllers::InputController::InputController() {
	_input_controller = std::make_unique<Input::Controllers::InputController>();
}

void Game::Controllers::InputController::poll_events() {
	_input_controller->subscribe(this->shared_from_this());
	_input_controller->poll_events();
}

void Game::Controllers::InputController::update(const Input::Enums::EventEnum& object)
{
	switch (object) {
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		std::cout << "links" << std::endl;
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		std::cout << "rechts" << std::endl;
		break;
	case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT: {
		std::tuple<int, int> pos = _input_controller->get_mouse_position();
		std::cout << "left click position: " << std::get<0>(pos) << ", " << std::get<1>(pos) << std::endl;
		break;
	}
	case Input::Enums::EventEnum::MOUSE_PRESSED_RIGHT: {
		std::tuple<int, int> pos = _input_controller->get_mouse_position();
		std::cout << "right click position: " << std::get<0>(pos) << ", " << std::get<1>(pos) << std::endl;
		break;
	}
	default:
		std::cout << "geen reactie" << std::endl;
	}
}
