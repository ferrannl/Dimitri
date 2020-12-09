#include "LevelController.h"
#include "../Mediators/CommandMediator.h"
#include <src/Controllers/DocumentController.h>
#include "../Builder/LevelBuilder.h"
#include "../Models/Buttons/IncreaseGameSpeedButton.h"
#include <conio.h>
#include <stdio.h>
using namespace Game;

Game::Controllers::LevelController::LevelController(const std::shared_ptr<Controllers::WindowController> window_controller, const std::shared_ptr<Controllers::AudioController> audio_controller) :
	_window_controller{ window_controller }, Mediators::BaseComponent("LevelController")
{
	DocumentHandler::Controllers::DocumentController ctrl;

	std::vector<std::vector<int>> ret = ctrl.Read(Utility::Helpers::get_base_path() + "/assets/levels/level1.csv");
	Builder::LevelBuilder builder{};
	_level = builder.build(ret, audio_controller);
	_level->load_objects();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_level->add_music("failed", "/assets/audio/failed.wav");

	_state = Enums::LevelStateEnum::INACTIVE;
}

void Game::Controllers::LevelController::load_buttons()
{
	_level->load_buttons();
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::LevelController::get_textures() const
{
	return _level->get_textures();
}

void Game::Controllers::LevelController::set_speed(float speed)
{
	_level->set_speed(speed);
	_window_controller->set_speed(speed);
}

float Game::Controllers::LevelController::get_speed()
{
	return _level->get_speed();
}

void Game::Controllers::LevelController::update(const Game::Events::InputEvent& object)
{
	for (auto& b : _level->get_buttons())
	{
		b->update(object);
	}
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
			_objects_thread.detach();
			_level->stop_music("level1");
		}
		else if (new_state == Enums::LevelStateEnum::ACTIVE) {
			// pause/win/game_over/inactive -> active
			_simulation_thread = std::thread(&Game::Controllers::LevelController::simulate, this);
			_objects_thread = std::thread(&Game::Controllers::LevelController::simulate_objects, this);
			_level->play_music("level1");
		}
		Mediators::CommandMediator::instance()->notify(*this, new_state);
	}
}

void Game::Controllers::LevelController::turn_off_light(const int x)
{
	for (std::shared_ptr<Models::Object> l : _level->get_updatables()) {
		if (l->get_x() == x) {
			l->get_texture()->set_visible(false);
		}
	}
}

void  Game::Controllers::LevelController::simulate() {
	while (_state == Enums::LevelStateEnum::ACTIVE) {
		sleep_for(1ms);

		_level->simulate();

		_level->get_player()->update();

		for (std::shared_ptr<Models::Object> walls : _level->get_tiles())
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

void  Game::Controllers::LevelController::simulate_objects() {
	while (_state == Enums::LevelStateEnum::ACTIVE) {
		sleep_for(36ms);


		for (std::shared_ptr<Models::Updatable> object : _level->get_updatables())
		{
			object->update_object(this);
		}

		_level->get_player()->update_state();
	}
}

Enums::LevelStateEnum Game::Controllers::LevelController::get_state() const
{
	return _state;
}
