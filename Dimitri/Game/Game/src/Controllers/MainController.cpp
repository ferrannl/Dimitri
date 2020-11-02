#include "MainController.h"
using namespace Game;
Controllers::MainController::MainController()
{
	_window_controller = std::make_unique<WindowController>();
	_input_controller = std::make_shared<Controllers::InputController>();
	_level = std::make_shared<Models::Level>();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_level->play_music("level1");
	_input_controller->poll_events();
}