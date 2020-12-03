#include "LevelController.h"
#include <src/Controllers/DocumentController.h>
#include "../Builder/LevelBuilder.h"
#include <conio.h> 
#include <stdio.h>
using namespace Game;

Game::Controllers::LevelController::LevelController(const std::shared_ptr<Controllers::WindowController> window_controller, const std::shared_ptr<Controllers::AudioController> audio_controller) : _window_controller{ window_controller }
{
	DocumentHandler::Controllers::DocumentController ctrl;

	std::vector<std::vector<int>> ret = ctrl.Read(Utility::Helpers::get_base_path() + "/assets/levels/level1.csv");
	Builder::LevelBuilder builder{};
	_level = builder.build(ret, audio_controller, window_controller);
	_level->load_objects();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_level->add_music("failed", "/assets/audio/failed.wav");

	_state = Enums::LevelStateEnum::INACTIVE;
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::LevelController::get_textures() const
{
	return _level->get_textures();
}

std::shared_ptr<Game::Models::Level> Game::Controllers::LevelController::get_level() const {
	return _level;
}

void Game::Controllers::LevelController::update(const Game::Events::InputEvent& object)
{
	switch (object.event_enum) {
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		if (_state == Enums::LevelStateEnum::ACTIVE) {
			_level->get_player()->set_direction(Game::Enums::DirectionEnum::LEFT);

			_level->get_player()->get_shape()->move_x(-1);
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		if (_state == Enums::LevelStateEnum::ACTIVE) {
			_level->get_player()->set_direction(Game::Enums::DirectionEnum::RIGHT);

			_level->get_player()->get_shape()->move_x(1);
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_UP:
		if (_state == Enums::LevelStateEnum::ACTIVE) {
			_level->get_player()->set_state(Game::Enums::StateEnum::JUMPING);

			if (_level->get_player()->jump()) {
				_level->get_player()->get_shape()->move_y();
			}
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_E:
		if (_state == Enums::LevelStateEnum::ACTIVE) {
			for (std::shared_ptr<Models::Interactable> interactable : _level->get_interactables())
			{
				if (_level->get_player()->get_shape()->check_square_collision(interactable->get_shape()))
				{
					interactable->interact(this);
				}
			}
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_P:
		if (_state == Enums::LevelStateEnum::ACTIVE) {
			set_state(Enums::LevelStateEnum::PAUSED);
		}
		else if (_state == Enums::LevelStateEnum::PAUSED) {
			start();
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_W:
		// this will obviously be triggered by an event in the future, for now a hardcoded key
		set_state(Enums::LevelStateEnum::WIN);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_G:
		// this will obviously be triggered by an event in the future, for now a hardcoded key
		set_state(Enums::LevelStateEnum::GAME_OVER);
		break;
	}
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
			_window_controller->get_graphics_controller()->get_window()->get_facade()->get_timer()->pause();
		}
		else if (new_state == Enums::LevelStateEnum::ACTIVE) {
			// pause/win/game_over/inactive -> active
			_simulation_thread = std::thread(&Game::Controllers::LevelController::simulate, this);
			_objects_thread = std::thread(&Game::Controllers::LevelController::simulate_objects, this);
			_level->play_music("level1");
			_window_controller->get_graphics_controller()->get_window()->get_facade()->get_timer()->unpause();
		}
		notify(_state);
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
		//std::cout << _level->get_timer()->getTicks() / 1000.f << '\n';
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

void Game::Controllers::LevelController::notify(const Enums::LevelStateEnum& object) {
	for (auto observer : _observers) {
		observer->update(object);
	}
}

void Game::Controllers::LevelController::subscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::LevelStateEnum>>& observer) {
	_observers.push_back(observer);
}

void Game::Controllers::LevelController::unsubscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::LevelStateEnum>>& observer)
{
	_observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
}