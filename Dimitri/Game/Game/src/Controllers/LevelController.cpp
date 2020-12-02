#include "LevelController.h"
#include "../Mediators/CommandMediator.h"
using namespace Game;

Game::Controllers::LevelController::LevelController(const std::shared_ptr<Controllers::WindowController> window_controller, const std::shared_ptr<Controllers::AudioController> audio_controller) :
	_window_controller{ window_controller }, Mediators::BaseComponent("LevelController")
{
	_level = std::make_shared<Game::Models::Level>(audio_controller);
	_level->load_objects();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_level->add_music("failed", "/assets/audio/failed.wav");

	_state = Enums::LevelStateEnum::INACTIVE;
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::LevelController::get_textures() const
{
	return _level->get_textures();
}

void Game::Controllers::LevelController::update(const Game::Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

std::shared_ptr<Game::Models::Level> Game::Controllers::LevelController::get_level() const
{
	return _level;
}

void Game::Controllers::LevelController::start()
{
	set_state(Enums::LevelStateEnum::ACTIVE);
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
		Mediators::CommandMediator::instance()->notify(*this, new_state);
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