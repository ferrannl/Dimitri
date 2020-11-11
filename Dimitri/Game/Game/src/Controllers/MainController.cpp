#include "MainController.h"
using namespace Game;
Controllers::MainController::MainController()
{
	_window_controller = std::make_shared<WindowController>();
	_level_controller = std::make_shared<Controllers::LevelController>();
	_input_controller = std::make_shared<Controllers::InputController>();
}

void Game::Controllers::MainController::run()
{
	_input_controller->subscribe(this->shared_from_this());
	_input_controller->subscribe(_level_controller);
	_window_controller->create_window(1080, 720);
	_window_controller->set_level_textures(_level_controller->get_textures());
	_input_controller->poll_events();
}

void Controllers::MainController::update(const Events::InputEvent& object)
{
	switch (object.event_enum) {
	case Input::Enums::EventEnum::KEY_PRESS_C:
		_window_controller.get()->clear_views();
		_window_controller.get()->open_view("credits");
		_window_controller.get()->open_view("fps");
		_level_controller.get()->stop();
		break;
	case Input::Enums::EventEnum::KEY_PRESS_L:
		_window_controller.get()->clear_views();
		_window_controller.get()->open_view("level");
		_window_controller.get()->open_view("fps");
		_level_controller.get()->start();
		break;
	case Input::Enums::EventEnum::KEY_PRESS_F:
		_window_controller.get()->toggle_view_visibility("fps");
		break;
	case Input::Enums::EventEnum::KEY_PRESS_QUIT:
		exit(0);
	}
}
