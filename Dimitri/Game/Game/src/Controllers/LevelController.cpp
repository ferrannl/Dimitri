#include "LevelController.h"
#include "../Commands/CommandFactory.h"
using namespace Game;

Game::Controllers::LevelController::LevelController(const std::shared_ptr<Controllers::WindowController> window_controller, const std::shared_ptr<Controllers::AudioController> audio_controller) : _window_controller{ window_controller }
{
	_level = std::make_shared<Game::Models::Level>(audio_controller);
	_level->load_objects();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_state = Enums::LevelStateEnum::INACTIVE;
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("player_move_left"), Input::Enums::EventEnum::KEY_PRESS_LEFT));
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("player_move_right"), Input::Enums::EventEnum::KEY_PRESS_RIGHT));
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("player_jump"), Input::Enums::EventEnum::KEY_PRESS_UP));
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("player_interact"), Input::Enums::EventEnum::KEY_PRESS_E));
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("pause_level"), Input::Enums::EventEnum::KEY_PRESS_P));
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::LevelController::get_textures() const
{
	return _level->get_textures();
}

void Game::Controllers::LevelController::update(const Game::Events::InputEvent& object)
{
	for (auto& s : _shortcuts) {
		if (s->get_event() == object.event_enum) {
			s->get_command()->execute();
			break;
		}
	}
}

std::shared_ptr<Game::Models::Level> Game::Controllers::LevelController::get_level() const
{
	return _level;
}

void Game::Controllers::LevelController::start()
{
	set_state(Enums::LevelStateEnum::ACTIVE);
	Commands::CommandFactory::instance()->get_command("open_level_view")->execute();
}

void Game::Controllers::LevelController::stop()
{
	set_state(Enums::LevelStateEnum::INACTIVE);
}

void Game::Controllers::LevelController::set_state(Enums::LevelStateEnum new_state)
{
	if (new_state != _state) {
		auto old_state = _state;
		_state = new_state;

		if (old_state == Enums::LevelStateEnum::ACTIVE) {
			// active -> pause/win/game_over/inactive
			_simulation_thread.join();
			_level->stop_music("level1");
		}
		else if (new_state == Enums::LevelStateEnum::ACTIVE) {
			// pause/win/game_over/inactive -> active
			_simulation_thread = std::thread(&Game::Controllers::LevelController::simulate, this);
			_level->play_music("level1");
		}
	}
}

void  Game::Controllers::LevelController::simulate() {
	while (_state == Enums::LevelStateEnum::ACTIVE) {
		sleep_for(1ms);
		_level->simulate();
		_level->get_player()->update();
		for (std::shared_ptr<Models::IObject> walls : _level->get_tiles())
		{
			if (_level->get_player()->get_shape()->check_bottom_collision(walls->get_shape()))
			{
				_level->get_player()->reset_jump();
				break;
			}
		}
		_window_controller->set_camera_pos_based_on(_level->get_player());
	}
}

Enums::LevelStateEnum Game::Controllers::LevelController::get_state() const
{
	return _state;
}