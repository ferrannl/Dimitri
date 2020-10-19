#include "MainController.h"
using namespace Game;
Controllers::MainController::MainController()
{
	_window_controller = std::make_unique<WindowController>();
	_input_controller = std::make_shared<Controllers::InputController>();
	_input_controller->poll_events();
}
