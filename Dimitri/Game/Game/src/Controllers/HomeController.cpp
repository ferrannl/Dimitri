#include "HomeController.h"
using namespace Game;

Game::Controllers::HomeController::HomeController(int sceneheight, int scenewidth, std::shared_ptr<Game::Controllers::AudioController> audio_controller)
{
	_scene_height = sceneheight;
	_scene_width = scenewidth;
	_audio_controller = audio_controller;
	_audio_controller->add_music("homescreen1", "/assets/audio/homescreen.wav");
	_audio_controller->add_music("highscore", "/assets/audio/highscore.wav");
	_audio_controller->play_audio("homescreen1");
}

void Game::Controllers::HomeController::load_buttons(std::shared_ptr<Managers::LevelManager> level_manager)
{
	_buttons.push_back(std::make_shared<Game::Models::Buttons::HighscoreButton>(_scene_width - 130, _scene_height - 70, 1, 50, 110, Game::Enums::StateEnum::RIGHT, _scene_height));
	_buttons.push_back(std::make_shared<Game::Models::Buttons::StartButton>(_scene_width / 2 - 35, (_scene_height / 4 * 3) - 150, 1, 50, 70, Game::Enums::StateEnum::RIGHT, _scene_height, level_manager));
	_buttons.push_back(std::make_shared<Game::Models::Buttons::ExitButton>(_scene_width / 2 - 35, (_scene_height / 4 * 3) - 225, 1, 50, 70, Game::Enums::StateEnum::RIGHT, _scene_height));
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