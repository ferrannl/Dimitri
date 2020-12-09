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

	std::vector<std::vector<int>> ret = ctrl.Read(Utility::Helpers::get_base_path() + "/assets/levels/level1.csv");
	Builder::LevelBuilder builder{};
	_level = builder.build(ret, audio_controller);
	_level->load_objects();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_level->add_sound("failed", "/assets/audio/failed.wav");

	_state = Enums::LevelStateEnum::INACTIVE;
}

void Controllers::LevelController::load_buttons()
{
	Graphics::Models::Color color = { 255, 255, 255 };
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t;

	// pause
	std::vector<std::pair<std::string, std::string>> button_map{ { "Continue", "Paused::Start" }, { "Back to home", "Paused::Home" } };
	int i = 0;
	float w = 200;
	float h = 30;
	float w_text;
	for (auto b : button_map) {
		w_text = b.first.length() * 10;
		t = {
			std::make_shared<Graphics::Models::Sprite>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 5, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, _window_controller->get_window_width() / 2 - (w_text / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 6, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		_buttons.push_back({ Enums::LevelStateEnum::PAUSED, std::make_unique<Models::Button>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), h, w, t, b.second) });
		i++;
	}

	// game over
	button_map = { { "Try again", "GameOver::Start" }, { "Back to home", "GameOver::Home" } };
	i = 0;
	for (auto b : button_map) {
		w_text = b.first.length() * 10;
		t = {
			std::make_shared<Graphics::Models::Sprite>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 5, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, _window_controller->get_window_width() / 2 - (w_text / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 6, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		_buttons.push_back({ Enums::LevelStateEnum::GAME_OVER, std::make_unique<Models::Button>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), h, w, t, b.second) });
		i++;
	}

	// win
	button_map = { { "Back to home", "Win::Home" } };
	i = 0;
	for (auto b : button_map) {
		w_text = b.first.length() * 10;
		t = {
			std::make_shared<Graphics::Models::Sprite>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 5, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, _window_controller->get_window_width() / 2 - (w_text / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), 6, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		_buttons.push_back({ Enums::LevelStateEnum::WIN, std::make_unique<Models::Button>(_window_controller->get_window_width() / 2 - (w / 2), _window_controller->get_window_height() / 2 - (25 + 50 * i), h, w, t, b.second) });
		i++;
	}
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

void Controllers::LevelController::update(const Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

std::shared_ptr<Models::Level> Controllers::LevelController::get_level() const
{
	return _level;
}

void Controllers::LevelController::start()
{
	set_state(Enums::LevelStateEnum::ACTIVE);
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
			// active -> pause/win/game_over/inactive
			_simulation_thread.join();
			_objects_thread.detach();
			_level->stop_music("level1");
		}
		else if (new_state == Enums::LevelStateEnum::ACTIVE) {
			// pause/win/game_over/inactive -> active
			_simulation_thread = std::thread(&Controllers::LevelController::simulate, this);
			_objects_thread = std::thread(&Controllers::LevelController::simulate_objects, this);
			_level->play_music("level1");
		}
		Mediators::CommandMediator::instance()->notify(*this, new_state);
	}
}

void Controllers::LevelController::turn_off_light(const int x)
{
	for (std::shared_ptr<Models::Object> l : _level->get_updatables()) {
		if (l->get_x() == x) {
			l->get_texture()->set_visible(false);
		}
	}
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

Enums::LevelStateEnum Controllers::LevelController::get_state() const
{
	return _state;
}