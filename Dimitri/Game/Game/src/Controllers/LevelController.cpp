#include "LevelController.h"
#include "../Mediators/CommandMediator.h"
#include <src/Controllers/DocumentController.h>
#include "../Builder/LevelBuilder.h"
#include <conio.h>
#include <stdio.h>
using namespace Game;

Controllers::LevelController::LevelController(const std::shared_ptr<Controllers::WindowController> window_controller, const std::shared_ptr<Controllers::AudioController> audio_controller) :
	_window_controller{ window_controller }, Mediators::BaseComponent("LevelController")
{
	DocumentHandler::Controllers::DocumentController ctrl;

	std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> ret = ctrl.ReadTiledLevel(Utility::Helpers::get_base_path() + "/assets/levels/level1.json");
	Builder::LevelBuilder builder{};
	_level = builder.build(ret, audio_controller, window_controller);
	_level->load_objects();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_level->add_sound("failed", "/assets/audio/failed.wav");
	_level->add_music("secret", "/assets/audio/rasputin.mp3");
	_level->add_music("transition", "/assets/audio/running.wav");
	_state = Enums::LevelStateEnum::INACTIVE;
}

void Controllers::LevelController::load_buttons()
{
	Graphics::Models::Color color = { 255, 255, 255 };
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t;

	// pause
	_button_map = { { "Continue", Enums::ButtonEnum::PAUSED_START }, { "Back to home", Enums::ButtonEnum::PAUSED_HOME } };
	int i = 0;
	float w = 200;
	float h = 30;
	float w_text;
	for (auto b : _button_map) {
		w_text = b.first.length() * 10;
		t = {
			std::make_shared<Graphics::Models::Sprite>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 5, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, _window_controller->get_window_width() / 2 - (w_text / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 6, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		_buttons.push_back({ Enums::LevelStateEnum::PAUSED, std::make_unique<Models::Button>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), h, w, t, b.second) });
		i++;
	}

	// game over
	_button_map = { { "Try again", Enums::ButtonEnum::GAMEOVER_START }, { "Back to home", Enums::ButtonEnum::GAMEOVER_HOME } };
	i = 0;
	for (auto b : _button_map) {
		w_text = b.first.length() * 10;
		t = {
			std::make_shared<Graphics::Models::Sprite>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 5, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, _window_controller->get_window_width() / 2 - (w_text / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 6, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		_buttons.push_back({ Enums::LevelStateEnum::GAME_OVER, std::make_unique<Models::Button>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), h, w, t, b.second) });
		i++;
	}

	// win
	_button_map = { { "Back to home", Enums::ButtonEnum::WIN_HOME } };
	i = 0;
	for (auto b : _button_map) {
		w_text = b.first.length() * 10;
		t = {
			std::make_shared<Graphics::Models::Sprite>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 5, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, _window_controller->get_window_width() / 2 - (w_text / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 6, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		_buttons.push_back({ Enums::LevelStateEnum::WIN, std::make_unique<Models::Button>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), h, w, t, b.second) });
		i++;
	}

	t = {};

	//Gameplay speed
	_buttons.push_back({ Enums::LevelStateEnum::ACTIVE, std::make_unique<Models::Button>(205, 600, 20, 35, t, Enums::ButtonEnum::INCREASE_GAMEPLAY_SPEED) });
	_buttons.push_back({ Enums::LevelStateEnum::ACTIVE, std::make_unique<Models::Button>(115, 600, 20, 35, t, Enums::ButtonEnum::DECREASE_GAMEPLAY_SPEED) });
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Controllers::LevelController::get_textures(Enums::LevelStateEnum state) const
{
	switch (state) {
	case Enums::LevelStateEnum::ACTIVE:
		return _level->get_textures();
	default:
		std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
		for (auto& b : _buttons) {
			if (b.first == state) {
				for (auto& t : b.second->get_textures()) {
					button_textures.push_back(t);
				}
			}
		}
		return button_textures;
	}
	return _level->get_textures();
}

void Game::Controllers::LevelController::set_speed(float speed)
{
	_level->set_speed(speed);
	_window_controller->set_speed(speed);
}

float Game::Controllers::LevelController::get_speed()const
{
	return _level->get_speed();
}

std::shared_ptr<Game::Models::Level> Game::Controllers::LevelController::get_level() const
{
	return _level;
}

void Game::Controllers::LevelController::play_secret() {
	_level->stop_music("level1");
	_level->play_music("secret");
	
}

void Game::Controllers::LevelController::update(const Game::Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

void Controllers::LevelController::start()
{
	set_state(Enums::LevelStateEnum::TRANSITION);
}

void Controllers::LevelController::stop()
{
	set_state(Enums::LevelStateEnum::INACTIVE);
}

void Controllers::LevelController::set_state(Enums::LevelStateEnum new_state)
{
	if (new_state != _state) {
		auto old_state = _state;
		_state = new_state;

		if (old_state == Enums::LevelStateEnum::ACTIVE) {
			// active -> pause/win/game_over/inactive/transition
			_simulation_thread.join();
			_objects_thread.detach();
			_level->stop_music("level1");
			_window_controller->get_graphics_controller()->get_window()->get_facade()->get_timer()->pause();
		}
		else if (old_state == Enums::LevelStateEnum::TRANSITION) {
			// transition -> active/pause/win/game_over/inactive
			_transition_thread.detach();
			_level->stop_music("transition");
		}

		if (new_state == Enums::LevelStateEnum::ACTIVE) {
			// pause/win/game_over/inactive/transition -> active
			_simulation_thread = std::thread(&Game::Controllers::LevelController::simulate, this);
			_objects_thread = std::thread(&Game::Controllers::LevelController::simulate_objects, this);
			_level->play_music("level1");
			_window_controller->get_graphics_controller()->get_window()->get_facade()->get_timer()->unpause();
		}
		else if (new_state == Enums::LevelStateEnum::TRANSITION) {
			// active/pause/win/game_over/inactive -> transition
			_transition_thread = std::thread(&Game::Controllers::LevelController::run_transition, this);
			_level->play_music("transition");
		}
		Mediators::CommandMediator::instance()->notify(*this, new_state);
	}
}

void Game::Controllers::LevelController::toggle_light(const std::tuple<int, int> pos)
{
	for (std::shared_ptr<Models::Object> l : _level->get_updatables()) {
		if (l->get_x() == std::get<0>(pos) && l->get_y() == std::get<1>(pos)) {
			l->get_texture()->toggle_visible();
		}
	}
}

void Game::Controllers::LevelController::run_transition()
{
	while (_state == Enums::LevelStateEnum::TRANSITION) {
		sleep_for(5ms);
		if (!_window_controller->is_active(Enums::ViewEnum::LEVEL_TRANSITION)) { break; }
	}
	_window_controller->get_graphics_controller()->get_window()->get_facade()->get_timer()->start();
	set_state(Enums::LevelStateEnum::ACTIVE);
}

void  Controllers::LevelController::simulate() {
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

void  Controllers::LevelController::simulate_objects() {
	while (_state == Enums::LevelStateEnum::ACTIVE) {
		sleep_for(36ms);

		for (std::shared_ptr<Models::Updatable> object : _level->get_updatables())
		{
			object->update_object(this);
		}
		_level->get_player()->update_state();
	}
}

std::vector<Game::Models::Button*> Controllers::LevelController::get_buttons() const
{
	std::vector<Game::Models::Button*> buttons;
	for (auto& b : _buttons) {
		if (b.first == _state) {
			buttons.push_back(b.second.get());
		}
	}
	return buttons;
}

void Game::Controllers::LevelController::update_highscore()
{
	std::string record = std::to_string(_window_controller->get_graphics_controller()->get_window()->get_facade()->get_timer()->getTicks() / 1000.f);
	_window_controller->set_highscore_record<Views::HighscoreView>(record);
}

Enums::LevelStateEnum Game::Controllers::LevelController::get_state() const
{
	return _state;
}
