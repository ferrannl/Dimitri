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
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		_level_controller.get()->get_level().get()->get_player()->set_state(Game::Enums::StateEnum::LEFT);
		_level_controller.get()->get_level().get()->get_player()->get_shape()->move_x(-1);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		_level_controller.get()->get_level().get()->get_player()->set_state(Game::Enums::StateEnum::RIGHT);
		_level_controller.get()->get_level().get()->get_player()->get_shape()->move_x(1);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_UP:
		_level_controller.get()->get_level().get()->get_player()->get_shape()->move_y();
		break;
	case Input::Enums::EventEnum::KEY_PRESS_E:
		for (std::shared_ptr<Models::IInteractable> interactable : _level_controller.get()->get_level()->get_interactables())
		{
			if (_level_controller.get()->get_level().get()->get_physics_collision_controller()->check_collision(_level_controller.get()->get_level().get()->get_player()->get_shape(), interactable->get_shape()))
			{
				interactable->interact();
			}
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_QUIT:
		exit(0);
	}
}
