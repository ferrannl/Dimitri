#include "LevelController.h"
using namespace Game;

Game::Controllers::LevelController::LevelController(std::shared_ptr<Controllers::WindowController> window_controller) : _window_controller{window_controller}
{
	_level = std::make_shared<Game::Models::Level>();
	_level->load_objects();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_running = false;
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::LevelController::get_textures() const
{
	return _level->get_textures();
}

void Game::Controllers::LevelController::update(const Game::Events::InputEvent& object)
{
	switch (object.event_enum) {
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		_level->get_player()->set_state(Game::Enums::StateEnum::LEFT);
		_level->get_player()->get_shape()->move_x(-1);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		_level->get_player()->set_state(Game::Enums::StateEnum::RIGHT);
		_level->get_player()->get_shape()->move_x(1);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_UP:
		_level->get_player()->get_shape()->move_y();
		break;
	case Input::Enums::EventEnum::KEY_PRESS_E:
		for (std::shared_ptr<Models::IInteractable> interactable : _level->get_interactables())
		{
			if (_level->get_physics_collision_controller()->check_collision(_level->get_player()->get_shape(), interactable->get_shape()))
			{
				interactable->interact();
			}
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_L:
		if (_running) {
			stop();
		}
		else {
			_window_controller->set_level_size(_level->get_level_height(), _level->get_level_width());
			start();
		}
		break;
	}
}

std::shared_ptr<Game::Models::Level> Game::Controllers::LevelController::get_level() const
{
	return _level;
}

void Game::Controllers::LevelController::start()
{
	_running = true;
	_simulation_thread = std::thread(&Game::Controllers::LevelController::simulate, this);
	_level->play_music("level1");
}

void Game::Controllers::LevelController::stop()
{
	_running = false;
	_simulation_thread.join();
	_level->stop_music("level1");
}

void  Game::Controllers::LevelController::simulate() {
	while (_running) {
		sleep_for(1ms);
		_level->simulate();
		_level->get_player()->update();
		int x = (_level->get_player()->get_x() + _level->get_player()->get_width() / 2) - _window_controller->get_window_width() / 2;
		int y = (_level->get_player()->get_texture()->get_converted_y(_window_controller->get_window_height()) + _level->get_player()->get_height() / 2) - _window_controller->get_window_height() / 2;
		_window_controller->set_camera_pos(x , y);
	}
}