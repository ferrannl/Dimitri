#include "HomeController.h"
using namespace Game;

Game::Controllers::HomeController::HomeController(int sceneheight, int scenewidth, std::shared_ptr<Game::Controllers::AudioController> audio_controller)
{
	_scene_height = sceneheight;
	_scene_width = scenewidth;
	_audio_controller = audio_controller;
	_audio_controller->add_music("homescreen1", "/assets/audio/homescreen.wav");
	_audio_controller->play_audio("homescreen1");
}

void Game::Controllers::HomeController::load_buttons(std::shared_ptr<Managers::LevelManager> level_manager)
{
	_buttons.push_back(std::make_shared<Game::Models::Buttons::StartButton>(_scene_width / 2 - 35, (_scene_height / 4 * 3) - 150, 1, 50, 70, Game::Enums::DirectionEnum::NONE, _scene_height, level_manager, Graphics::Models::Center{ 0,0 } {  };));
	_buttons.push_back(std::make_shared<Game::Models::Buttons::ExitButton>(_scene_width / 2 - 35, (_scene_height / 4 * 3) - 225, 1, 50, 70, Game::Enums::DirectionEnum::NONE, _scene_height, Graphics::Models::Center{ 0,0 }));
	_buttons.push_back(std::make_shared<Game::Models::Buttons::AdvertisementButton>((_scene_width / 2) - (_scene_width / 4), 20, 1, 200, _scene_width / 2, Game::Enums::StateEnum::RIGHT, _scene_height, level_manager->get_window_controller(), Graphics::Models::Center{ 0,0 }));

}

void Game::Controllers::HomeController::update(const Game::Events::InputEvent& object)
{
	for (auto& b : _buttons)
		b->update(object);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::HomeController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : _buttons) {
		button_textures.push_back(b->get_texture());
	}
	return button_textures;
}

std::vector<std::shared_ptr<Game::Models::Button>> Game::Controllers::HomeController::get_advertisement_buttons()
{
	std::vector<std::shared_ptr<Game::Models::Button>> _advertisement_buttons = {};
	for (auto b : _buttons) {
		if (b->get_type() == Game::Enums::ButtonEnum::ADVERTISEMENT)
		{
			_advertisement_buttons.push_back(b);
		}
	}
	return _advertisement_buttons;
}
